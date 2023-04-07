function Pn = random_walk(N)
    Xn = 2 * randi([0, 1], 1, N) - 1;
    Sn = [0, cumsum(Xn)];

    Dn = zeros(1, N);
    for i = 2:(N + 1)
        if Sn(i) > 0
            Dn(i) = 1;
        elseif Sn(i-1) > 0
            Dn(i) = 1;
        end
    end

    Ln = sum(Dn);
    Pn = Ln / N;

    %plot(Sn);
end