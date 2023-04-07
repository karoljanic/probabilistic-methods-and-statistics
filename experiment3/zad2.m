SAMPLES_NUMBER = 100000;
N = 25;

VALS = zeros(1, SAMPLES_NUMBER);    
for i = 1:SAMPLES_NUMBER
    VALS(i) = sum(2 * randi([0, 1], 1, N) - 1);
end

X_VALS = -N:N;
NORM_CDF = normcdf(X_VALS, 0, sqrt(N));

hold on;
cdfplot(VALS);
plot(X_VALS, NORM_CDF);

title("Dystrybuanta zmiennej losowej Sn dla N = " + N);
xlabel("t");
ylabel("CDF(t)");
legend("Sn", "rozklad normalny");
