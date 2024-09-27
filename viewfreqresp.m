function viewfreqresp(filename, Fs)
    if nargin < 2
        Fs = 48000; % Frecuencia de muestreo por defecto
    end

    % Cargar la matriz SOS
    Data = load(filename, "SOS");
    SOS = Data.SOS;

    % Recuperar el filtro completo
    [B, A] = sos2tf(SOS);

    % Generar la respuesta en frecuencia
    freqs = logspace(0, log10(Fs/2), 1000); % Frecuencias de 1 Hz a Fs/2
    omega = 2 * pi * freqs / Fs; % Convertir a radianes por segundo

    % Evaluar H(z)
    H = @(z) polyval(B, z) ./ polyval(A, z);

    % Calcular la respuesta en frecuencia
    H_values = H(exp(1j * omega));
    mag = 20 * log10(abs(H_values)); % Magnitud en dB
    phase = angle(H_values) * (180 / pi); % Fase en grados

    % Ajustar la fase a un rango de -360 a 0
    phase = mod(phase + 360, 360) - 360;

    % Gráfico de la magnitud
    figure;
    subplot(2, 1, 1);
    semilogx(freqs, mag);
    xlabel('Frecuencia (Hz)');
    ylabel('Magnitud (dB)');
    grid on;
    title('Respuesta en Frecuencia');
    axis tight;
    ylim([-100 10]);

    % Gráfico de la fase
    subplot(2, 1, 2);
    semilogx(freqs, phase);
    xlabel('Frecuencia (Hz)');
    ylabel('Fase (grados)');
    grid on;
    axis tight;
    ylim([-360 0]);

    % Diagrama de polos y ceros
    figure;

    zplane(B, A);
    title('Diagrama de Polos y Ceros');
end

