% Conversion
oz2Kg  = 0.0283495231; % Ouncemass to Kilogram conversion factor
lb2N = 4.44822; % Pounds to Newton conversion factor

VRfromNED_cordT = [ 0  1  0
                    0  0 -1
                   -1  0  0]; % Coordinate transform from NED to VrSink Coords
body_VR_fromEarthVR = [1 0 0
                       0 0 -1
                       0 1 0]; % Coordinate Transform, Body in Vr from Earth Vr


% constants
g        = 9.81;

M_lander = 1183.149 * oz2Kg; % Kg mass of lander
T_min = 100 * lb2N; % N Min Thrust of Engine
T_max = 250 * lb2N; % N Max Thrust of Engine

% Inertia Values Ounce Mass, Converted to kg later
% Ixx = 3.099E+05;
% Ixy = -0.033;
% Ixz = 53.236;
% Iyx = -0.033;
% Iyy = 3.135E+05;
% Iyz = -3.933; % Old
% Izx = 53.236;
% Izy = -3.933;
% Izz = 2.323E+05;

% Kg m^2
Ixx =5.816;
Iyy = 5.735;
Izz = 4.289;
% From fusion with updated cm values. Products of inertia are negligible


% Dummy values
% 50 pounds of fuel
m_iFuel = 10; %Kg mass Fuel
m_dot = 1; %kg/s mass flow rate of fuel.
cmFuel_cmL = 0.2; % m distance between C.M of fuel to  C.M of Lander. 
                  % In Body Fixed Frame. 
k_Fuel = 3.5e3; % Spring Coefficient of mass spring damper approx for fuel
c_Fuel = 2.806e2; % Damper Coeff "   "

% ~~~ In body fixed frame
l_TV = 0.424; % Distance form CM land to acting point of thrust vector Updated 4/14/22
dev_x_TV = 0.1; % Deviation from true vertical x
dev_y_TV = 0.1; % "  " y
L_TV = [dev_x_TV dev_y_TV l_TV];

% Dependant Variables
W_lander = M_lander * g; % N weight of lander

% Old
% Ix_ = [Ixx Ixy Ixz];
% Iy_ = [Iyx Iyy Iyz];
% Iz_ = [Izx Izy Izz];
% 
% I = [Ix_
%      Iy_
%      Iz_];
% I = I .* oz2Kg;
I = [Ixx 0 0; 0 Iyy 0; 0 0  Izz];

%Dummy Value
symmetricalI = I .* eye(3); % Symmetrical Moment of Intertia To test pure rotations
linDrag = 0.01; % Translational Linear Drag Coefficient. Assumed.
angDrag = 0.01; % Rotational linear drag coefficient. Assumed.

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

% Center of Tank is 0.184m above center of mass of Lander. Updated
% 4/14/22

mag_CM_Fuel_b = norm(CM_FUEL_b);

% Other scripts
pendulum2Dss % Define K proportional control value

%% Scripts in matlab function blocks
% function Thrust_unit_vec = fcn(phi, theta)
% C_phi = [1     0        0
%          0 cos(phi) sin(phi) 
%          0 -sin(phi) cos(phi)];
% C_theta = [cos(theta) 0 -sin(theta)
%            0          1           0
%            sin(theta) 0 cos(theta)];
% 
% C_trans = C_theta * C_phi;
% 
% Thrust_unit_vec = C_trans.' * [0 0 -1];
% 
% end
% 
% function rotMatrix = fcn(u)
% 
% rotMatrix = eul2rotm(u, 'XYZ')
% 
% end
