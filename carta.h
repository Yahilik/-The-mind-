class Carta {
private:
    int numeroCarta;
public:
    Carta(int n = 0) : numeroCarta(n) {}
    int getNumero() const { return numeroCarta; }
};
