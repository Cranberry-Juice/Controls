M = 1; %kg mass of engine
m = M_lander; % kg
l = l_TV; %m distance from Cm lander to engine
g = 9.81;
bt = 0.1; % Angular Friction coeff, due to air, and fuel tank
bx = 0.1; % Translational Friction Coeff. "   "


% State Vector
% X = [x; theta; xdot; thetadot] For reference. 

% Force X controller. Controlls Roll. 
AX = [0  0                   1         0
      0  0                   0         1
      0 (g * m)/M            bx/M      bt/(l * M)
      0 (g * (m + M))/(l* M) bx/(l *M) ((m + M) * bt)/(l^2 * m * M)];
BX = [0
     0
     -1/M
     -1/(l * M)];
% Force Y Controller. Controlls Pitch. 
AY = [0  0                     1          0
      0  0                     0          1
      0 -(g * m)/M             bx/M      -bt/(l * M)
      0  (g * (m + M))/(l* M) -bx/(l *M)  ((m + M) * bt)/(l^2 * m * M)];
BY = [0
     0
     -1/M
     1/(l * M)];

% if rank(ctrb(A,B) == 4, this model is controllable.
% rank(ctrb(AY, BY))
% rank(ctrb(AX, BX))

C = [1 0 0 0
     0 1 0 0];
D = 0;

Q = [200 0    0     0
     0     10   0     0
     0     0   0.1  0
     0     0    0     1];

R = 0.10;

KX = lqr(AX, BX, Q, R);
KY = lqr(AY, BY, Q, R);