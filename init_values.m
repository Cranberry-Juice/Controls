% Conversion
oz2Kg  = 0.0283495231; % Ouncemass to Kilogram conversion factor
lb2N = 4.44822; % Pounds to Newton conversion factor

% constants
g        = 9.81;

M_lander = 1183.149 * oz2Kg; % Kg mass of lander
T_min = 100 * lb2N; % N Min Thrust of Engine
T_max = 250 * lb2N; % N Max Thrust of Engine

% Inertia Values Ounce Mass, Converted to kg later
Ixx = 3.099E+05;
Ixy = -0.033;
Ixz = 53.236;
Iyx = -0.033;
Iyy = 3.135E+05;
Iyz = -3.933;
Izx = 53.236;
Izy = -3.933;
Izz = 2.323E+05;



% Dummy values
m_iFuel = 10; %Kg mass Fuel
m_dot = 0; %kg/s mass flow rate of fuel.
cmFuel_cmL = 0.2; % m distance between C.M of fuel to  C.M of Lander. 
                  % In Body Fixed Frame. 
k_Fuel = 3.5e3; % Spring Coefficient of mass spring damper approx for fuel
c_Fuel = 2.806e2; % Damper Coeff "   "

% Dependant Variables
W_lander = M_lander * g; % N weight of lander

Ix_ = [Ixx Ixy Ixz];
Iy_ = [Iyx Iyy Iyz];
Iz_ = [Izx Izy Izz];

I = [Ix_
     Iy_
     Iz_];
I = I .* oz2Kg;


% Vectors
% NORTH EAST DOWN CONVENTION. 
% X POSITIVE FORWARD, Y POSITIVE RIGHT, Z POSITIVE DOWN.    
% 
% All caps denotes vectors.
W_LANDER = [0
            0
            W_lander]; % In inertial frame



% Dummy Vectors
CM_FUEL_b = [0
           0
           -cmFuel_cmL]; % Position Vector. Center of mass of Fuel in body frame


