#include "Carapace.h"
#include "UImg.h"
#include <cmath>

Carapace::Carapace(Bestiole &b, double deathCoeff, double speedCoeff) {
    this->deathCoeff = deathCoeff;
    this->speedCoeff = speedCoeff;
    this->bestiole = &b;
}

Carapace::Carapace(Bestiole &b) {
    //TODO: Implementer le constructeur
}

void Carapace::draw(UImg &support, double x, double y, double orientation) {
    // Implémentation spécifique de la carapace
    const double width = 20.0;
    const double height = 10.0;
    const double angle = orientation * M_PI / 180.0;

    double x1 = x + width * cos(angle) - height * sin(angle);
    double y1 = y + width * sin(angle) + height * cos(angle);
    double x2 = x - width * cos(angle) - height * sin(angle);
    double y2 = y - width * sin(angle) + height * cos(angle);
    double x3 = x - width * cos(angle) + height * sin(angle);
    double y3 = y - width * sin(angle) - height * cos(angle);
    double x4 = x + width * cos(angle) + height * sin(angle);
    double y4 = y + width * sin(angle) - height * cos(angle);

    unsigned char black[] = {0, 0, 0};
    support.draw_line(x1, y1, x2, y2, black);
    support.draw_line(x2, y2, x3, y3, black);
    support.draw_line(x3, y3, x4, y4, black);
    support.draw_line(x4, y4, x1, y1, black);
}