pkg load signal
pkg load audio
function listen_filter(filter_filename, audio_filename, Fs)
    if nargin < 3
        Fs = 48000; % Frecuencia de muestreo por defecto
    end

    Data = load(filter_filename, "SOS");
    SOS = Data.SOS;

    [B, A] = sos2tf(SOS);

    [audio, original_fs] = audioread(audio_filename);

    if original_fs ~= Fs
        audio = resample(audio, Fs, original_fs); % Cambiar la frecuencia de muestreo si no coinciden
    end

    %filtrado
    filtered_audio = filter(B, A, audio);

    % Reproducir audio
    sound(filtered_audio, Fs);

    %Guardar
    Outputaux=substr(filter_filename,6);
    Outputaux1=substr(audio_filename,12);
    Outputaux=[Outputaux,'_'];
    Outputaux=[Outputaux,Outputaux1];
    output_filename=['AudioFiles/Filtered/Filtered_',Outputaux];
    audiowrite(output_filename, filtered_audio, Fs);

    fprintf('Audio filtrado guardado como: %s\n', output_filename);
end

