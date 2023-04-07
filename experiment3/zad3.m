K = 5000;
N = 100;

data = zeros(1, K);
for i = 1:K
    data(i) = random_walk(N);
end

hold on
histogram(data, 20, 'Normalization', 'pdf');

syms x
arc_dist = 1 / ( pi * sqrt(x * (1 - x)));
plt = fplot(arc_dist, [0, 1]);
plt.ShowPoles = false;

title("Gestosc rozkladu Pn dla N = " + N);
xlabel("t");
ylabel("PDF(t)");
ylim([0, 5]);
legend("rozklad Pn", "rozklad arcsinus");