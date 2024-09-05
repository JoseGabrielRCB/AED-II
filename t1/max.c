void SquareCycle(double posX1, double posY1, double posX2, double posY2, int level) // location 1 - Cima, 2 - Baixo, 3 - Esquerda, 4 - Direita
{
    if (level == 0) // Para a recursao quando o valor n alcanca 0
        return;
    SquareCycle(posX1 + ((posX2 - posX1) / 4), posY1 - ((posY2 - posY1) / 2), posX2 - ((posX2 - posX1) / 4), posY1, level - 1); // Recebe a coordenada do quadrado de cima
    SquareCycle(posX1 + ((posX2 - posX1) / 4), posY2, posX2 - ((posX2 - posX1) / 4), posY2 + ((posY2 - posY1) / 2), level - 1); // Recebe a coordenada do quadrado de baixo
    SquareCycle(posX1 - ((posX2 - posX1) / 2), posY1 + ((posY2 - posY1) / 4), posX1, posY2 - ((posY2 - posY1) / 4), level - 1); // Recebe a coordenada do quadrado esquerdo
    SquareCycle(posX2, posY1 + ((posY2 - posY1) / 4), posX2 + ((posX2 - posX1) / 2), posY2 - ((posY2 - posY1) / 4), level - 1); // Recebe a coordenada do quadrado direito

    gfx_set_color(255, 255, 255);
    gfx_rectangle(posX1, posY1, posX2, posY2);
    gfx_set_color(0, 0, 0);
    gfx_filled_rectangle(posX1 + 1, posY1 + 1, posX2 - 1, posY2 - 1);
    return;
}