M = 1; %kg mass of engine
m = M_lander; % kg
l = l_TV; %m distance from Cm lander to engine
g = 9.81;
bt = 0.1; % Angular Friction coeff, due to air, and fuel tank
bx = 0.1; % Translational Friction Coeff. "   "
% 
% A = [0 0 0 0 0 1 0 0 0 0
%      0 0 0 0 0 0 1 0 0 0
%      0 0 0 0 0 0 0 1 0 0
%      0 0 0 0 0 0 0 0 1 0
%      0 0 0 0 0 0 0 0 0 1
%      0 0 0 0 0 0 0 0 0 0
%      0 0 0 0 0 0 0 0 0 0
%      0 0 0 0 0 0 0 0 0 0
%      0 0 0 0 0 0 0 0 0 0
%      0 0 0 0 0 0 0 0 0 0];
% 
% B = [0              0            0
%      0              0            0
%      0              0            0
%      0              0            0
%      0              0            0
%      0              0           -m/(M * (m+M))     
%      0              0            m/(M * (m+M))
%      m/(M * (m+M)) -m/(M * (m+M)) 0
%      0              0           -l/M
%      0              0           -l/M];
% 
% C = [0 0 1 0 0 0 0 0 0 0
%      0 0 0 1 0 0 0 0 0 0
%      0 0 0 0 1 0 0 0 0 0
%      0 0 0 0 0 0 0 0 0 0
%      0 0 0 0 0 0 0 0 0 0
%      0 0 0 0 0 0 0 0 0 0
%      0 0 0 0 0 0 0 0 0 0
%      0 0 0 0 0 0 0 0 0 0
%      0 0 0 0 0 0 0 0 0 0
%      0 0 0 0 0 0 0 0 0 0];
% 
% D = 0;
% % 
% % sys = ss(A,B,C,D);
% % Wc = gram(sys,"c");
% % Wo = gram(sys, 'o');
% % [sysb, g, Ti, T] = balreal(sys);
% % 
% % BWo = gram(sysb, 'c')
% % BWo = gram(sysb, 'o')
% 
% % eigs = [-1.1; -1.2; -1.3; -1.4];
% Q = [0.1 0   0   0     0   0   0   0   0   0
%      0   0.1 0   0     0   0   0   0   0   0
%      0   0   0.1 0     0   0   0   0   0   0
%      0   0   0   100   0   0   0   0   0   0
%      0   0   0   0     100 0   0   0   0   0
%      0   0   0   0     0   0.1 0   0   0   0
%      0   0   0   0     0   0   0.1 0   0   0
%      0   0   0   0     0   0   0   0.1 0   0
%      0   0   0   0     0   0   0   0   0.1 0
%      0   0   0   0     0   0   0   0   0   0.1];
% R = 0.001;
% % K = place(A,B, eigs);
% K = lqr(A, B, Q, R);
% 
% eig(A-B*K)

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
%Kalman Filter

xState = ss(AX, BX, C, D);
ySatte = ss(AY, BY, C, D)
KX = lqr(AX, BX, Q, R);
KY = lqr(AY, BY, Q, R);