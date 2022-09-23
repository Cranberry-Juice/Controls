nsamples = 50; % Number of samples for numerical estimation

% Expected operating range of thurst vector deflectin angle.
thMin = -15; % Degrees, 
thMax = 15; % Degrees.

TyMin = 1; % Ty/Weight. Minimum thrust expected.
TyMax = 2; % Ty/Wight, Max Vertical thrust expected.

theta = linspace(thMin, thMax, nsamples);
Ty = linspace(TyMin, TyMax, nsamples);

[TY, TH] = meshgrid(Ty, theta);

Tx = TY .* tand(TH);

surf(TY, TH, Tx)

xlabel("T_{vert}/W Ratio")
ylabel("Vane Angle (deg)")
zlabel('T_{hori}/W Ratio')


Thrust = sqrt(Tx.^2 + TY.^2);

figure
surf(Tx, TY, Thrust)
xlabel("T_{hori}/W Ratio")
ylabel("T_{vert}/W Ratio")
zlabel('T/W Ratio')