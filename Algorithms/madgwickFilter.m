function [roll, pitch, yaw] = madgwickFilter(ax, ay, az, gx, gy, gz, beta, deltaT)
    persistent q_est;
    
    if isempty(q_est)
        q_est = [1; 0; 0; 0]; % Initial quaternion estimate
    end
    
    % Normalize accelerometer data
    a_norm = [ax; ay; az] / norm([ax, ay, az]);
    
    % Compute gradient and update quaternion using sensor data
    q_est_prev = q_est;
    q_w = [0; gx; gy; gz] * (deltaT / 2);
    
    gradient = computeGradient(q_est_prev, a_norm, beta);
    q_est_dot = q_w - gradient * deltaT;
    q_est = q_est_prev + q_est_dot * deltaT;
    q_est = quatnormalize(q_est'); % Normalize quaternion
    
    % Convert quaternion to Euler angles
    [yaw, pitch, roll] = quat2angle(q_est', 'ZYX');
    yaw = rad2deg(yaw);
    pitch = rad2deg(pitch);
    roll = rad2deg(roll);
end

function gradient = computeGradient(q_est, a_norm, beta)
    F_g = 2 * [q_est(2)*q_est(4) - q_est(1)*q_est(3) - a_norm(1);
               q_est(1)*q_est(2) + q_est(3)*q_est(4) - a_norm(2);
               0.5 - q_est(2)^2 - q_est(3)^2 - a_norm(3)];
           
    J_g = [-2*q_est(3), 2*q_est(4), -2*q_est(1), 2*q_est(2);
            2*q_est(2), 2*q_est(1), 2*q_est(4), 2*q_est(3);
            0, -4*q_est(2), -4*q_est(3), 0];
        
    gradient = J_g' * F_g;
    gradient = gradient * beta;
end
