pkg load signal

Fs = 48000; % Frecuencia de muestreo
Nyquist = Fs / 2; % Frecuencia de Nyquist

% Especificaciones de los filtros
rizado_db = 1; % Rizado en dB para los filtros pasabanda
atenuacion_db = 50; % Atenuación en dB para los filtros de rechazo

% Frecuencias de corte
f_low = 440; % Frecuencia de corte para el filtro paso bajo
f_high = 600; % Frecuencia de corte para el filtro paso alto
f_bandpass_low = 220; % Frecuencia de corte inferior para paso banda
f_bandpass_high = 1000; % Frecuencia de corte superior para paso banda
f_stopband_low = 220; % Frecuencia de corte inferior para supresor de banda
f_stopband_high = 1000; % Frecuencia de corte superior para supresor de banda

% Normalización de frecuencias
W_low = f_low / Nyquist;
W_high = f_high / Nyquist;
W_bandpass = [f_bandpass_low f_bandpass_high] / Nyquist;
W_stopband = [f_stopband_low f_stopband_high] / Nyquist;

% Filtros
methods = {'ellip', 'butter', 'cheby1', 'cheby2'};
filter_types = {'lowpass', 'highpass', 'bandpass', 'stopband'};
frequencies = {W_low, W_high, W_bandpass, W_stopband};

%Elip filters
for t = 1:length(filter_types)
    switch filter_types{t}
        case 'lowpass'
          [b, a] = ellip(3,rizado_db,atenuacion_db,W_low,'low');
        case 'highpass'
          [b, a] = ellip(3,rizado_db,atenuacion_db, W_high, 'high');
        case 'bandpass'
          [b, a] = ellip(3,rizado_db,atenuacion_db,W_bandpass);
        case 'stopband'
          [b, a] = ellip(3,rizado_db,atenuacion_db,W_stopband, 'stop');
    end
    % Convertir a forma SOS
    SOS = tf2sos(b, a);

    % Guardar en archivo
    filename = sprintf('Mats/%s_%s.mat', methods{1}, filter_types{t});
    save(filename, 'SOS');
end

%butter
for t = 1:length(filter_types)
    switch filter_types{t}
        case 'lowpass'
          [b, a] = butter(3,W_low,'low');
        case 'highpass'
          [b, a] = butter(3,W_high,'high');
        case 'bandpass'
          [b, a] = butter(3,W_bandpass,'bandpass');
        case 'stopband'
          [b, a] = butter(3,W_stopband, 'stop');
    end
    % Convertir a forma SOS
    SOS = tf2sos(b, a);

    % Guardar en archivo
    filename = sprintf('Mats/%s_%s.mat', methods{2}, filter_types{t});
    save(filename, 'SOS');
end


%cheby1
for t = 1:length(filter_types)
    switch filter_types{t}
        case 'lowpass'
          [b, a] = cheby1(3,rizado_db,W_low,'low');
        case 'highpass'
          [b, a] = cheby1(3,rizado_db,W_high,'high');
        case 'bandpass'
          [b, a] = cheby1(3,rizado_db,W_bandpass);
        case 'stopband'
          [b, a] = cheby1(3,rizado_db,W_stopband, 'stop');
    end
    % Convertir a forma SOS
    SOS = tf2sos(b, a);

    % Guardar en archivo
    filename = sprintf('Mats/%s_%s.mat', methods{3}, filter_types{t});
    save(filename, 'SOS');
end

%cheby1
for t = 1:length(filter_types)
    switch filter_types{t}
        case 'lowpass'
          [b, a] = cheby1(3,atenuacion_db,W_low,'low');
        case 'highpass'
          [b, a] = cheby1(3,atenuacion_db,W_high,'high');
        case 'bandpass'
          [b, a] = cheby1(3,atenuacion_db,W_bandpass);
        case 'stopband'
          [b, a] = cheby1(3,atenuacion_db,W_stopband, 'stop');
    end
    % Convertir a forma SOS
    SOS = tf2sos(b, a);

    % Guardar en archivo
    filename = sprintf('Mats/%s_%s.mat', methods{4}, filter_types{t});
    save(filename, 'SOS');
end

