function filtered_data = moving_average_filter(data, filter_type, window_size)
    % data: Input data to be filtered
    % filter_type: 'ma' for moving average, 'median' for median filter
    % window_size: Size of the filter window
    
    if strcmp(filter_type, 'ma')
        filtered_data = movmean(data, window_size);
    elseif strcmp(filter_type, 'median')
        filtered_data = medfilt1(data, window_size);
    else
        error('Invalid filter type. Use ''ma'' for moving average or ''median'' for median filter.');
    end
end