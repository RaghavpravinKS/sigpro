accelData = [your_accelerometer_data]; 

% Calculate mean and standard deviation for each axis
meanX = mean(accelData(:, 1));
meanY = mean(accelData(:, 2));
meanZ = mean(accelData(:, 3));

stdDevX = std(accelData(:, 1));
stdDevY = std(accelData(:, 2));
stdDevZ = std(accelData(:, 3));

% Set thresholds for each axis as multiples of the standard deviation above the mean
thresholdX = meanX + 2 * stdDevX;
thresholdY = meanY + 2 * stdDevY;
thresholdZ = meanZ + 2 * stdDevZ;
