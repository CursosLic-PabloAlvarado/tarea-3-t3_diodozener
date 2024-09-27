pkg load signal
% Parámetros
fs = 48000;              % Frecuencia de muestreo
t = 0:1/fs:15;           % Tiempo de 0 a 15 segundos
f_start = 20;           % Frecuencia inicial
f_end = 20000;          % Frecuencia final

% Barrido de frecuencias
signal = chirp(t, f_start, t(end), f_end);
audiowrite('AudioFiles/barrido_frecuencias.wav', signal, fs);

t = 0:1/fs:10;
% Generar ruido blanco
noise = randn(size(t));

% Normalizar el ruido para que esté entre -1 y 1
noise = noise / max(abs(noise));

audiowrite('AudioFiles/ruido_blanco.wav', noise, fs);

