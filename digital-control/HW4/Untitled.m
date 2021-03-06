a = zeros(11,2);

a(:,1) = [0.1,0.15,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1];
a(:,2) = [157.5,312.5,373.3,420.2,439.3,455.5,472.8,483.1,495.4,505.4,519.6];

f1 = figure();
hold on
plot(a(:,1),a(:,2))
ylim([0,600]);

f = fit(a(4:11,1),a(4:11,2),'poly1');

plot(a(:,1),f.p1*a(:,1)+f.p2)
hold off
% a(1,1) = 157.5; % 10% duty cycle
% a(2,1) = 373.3;
% a(3,1) = 420.2;
% a(4,1) = 439.3;
% a(5,1) = 455.5;
% a(6,1) = 472.8;
% a(7,1) = 483.1;
% a(8,1) = 495.4;
% a(9,1) = 505.4; 
% a(10,1) = 519.6; % 100%
% 
% a(11,1) = 313.5;
% 
% 
time = 0:174*0.05:0.05;

