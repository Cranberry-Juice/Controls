%clear
m_r    = 0.5;        %kg mass of rocket
g      = 9.81;       %m/s^2
Tmax   = 10;         %N Max Thrust
t_burn = 2;          %s total burn time
m_d_c  = 0.01;       %kg/s^2 mass flow rate const| dummy number
rho    = 1.225;      %0 0kg/m^3 air density
R_rad  = 0.03;       %m radius of rocket
Cd     = 0.5;        %Rocket Drag Coeff
Ar     = pi*R_rad^2; %Reference Area Rocket

% sdf