close all
hold off

Tx = out.Tx_m;
Ty = out.Ty_m;
Tz = out.Tz_m;

X = out.X_pos;
Y = out.Y_pos;
Z = out.Z_pos;
tout = out.tout;

grid on
xlim manual
ylim manual
zlim manual
xlim([-100 50])
ylim([-100 50])
zlim([-50 400])
view([-1 -1.4 0.5])
path = animatedline;

for i = 1:length(tout)
    addpoints(path,X(i), Y(i), Z(i))
    drawnow
    
    xlabel('x')
    ylabel('y')
    zlabel('z')
end

figure
%% Animate Thrust Vector
sz = size(Tx);
l = max(sz);
O_ = zeros(sz);

T_0 = [O_, O_, O_]; %Empty Matrix for reuse

T = [Tx, Ty, Tz];


T_q = quiver3(O_, O_, O_, Tx, Ty, Tz);


xlim([-3 3])
ylim([-3 3])
zlim([0 20])
view([-1 -1.4 0.5])
for i = 1:l

    T_i = T_0;

    T_i(i,:) = T(i,:);

    T_q.UData = T_i(:,1);
    T_q.VData = T_i(:,2);
    T_q.WData = T_i(:,3);
    
    pause(.15)
    
end

