pkg load signal
function listen_filter(filter_filename, audio_filename, Fs)
    if nargin < 3
        Fs = 48000; % Frecuencia de muestreo por defecto
    end

    % Cargar la matriz SOS desde el archivo del filtro
    Data = load(filter_filename, "SOS");
    SOS = Data.SOS;

    % Recuperar el filtro completo (numerador y denominador)
    [B, A] = sos2tf(SOS);

    % Leer el archivo de audio
    [audio, original_fs] = audioread(audio_filename);

    % Verificar si la frecuencia de muestreo del audio coincide
    if original_fs ~= Fs
        audio = resample(audio, Fs, original_fs); % Cambiar la frecuencia de muestreo si es necesario
    end

    % Aplicar el filtro al audio
    filtered_audio = filter(B, A, audio);

    % Reproducir el audio filtrado
    sound(filtered_audio, Fs);

    % Opcional: guardar el audio filtrado en un nuevo archivo
    output_filename = sprintf('filtered_%s', audio_filename);
    audiowrite(output_filename, filtered_audio, Fs);

    fprintf('Audio filtrado guardado como: %s\n', output_filename);
end

