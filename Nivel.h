#ifndef NIVEL_H
#define NIVEL_H

class Nivel {
private:
    int NumeroNivel;
    int recompensaVida;
    int recompensaShuriken;
public:
    Nivel(int n = 1);
    void CompletarNivel() const;
    void DarRecompensa(int &vidas, int &shurikens) const;
};

#endif
