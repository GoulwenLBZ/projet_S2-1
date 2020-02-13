#define AddrLCD 0x4E // 0x27 < 1


void init_LCD();

void Affiche_temp();
void Affiche_hygro();
void Affiche_press();
void Date_heure();
void LCD_CLEAR();
void Affiche_vitesse_vent();
void Affiche_direction_vent();
void Erreur_hygro();
void Erreur_temp();
void Erreur_Date_heure();
void Erreur_vent();
void Erreur_press();
void Ecran_de_base();
void Ecran_de_localisation();
void Ecran_Histo_temp();
void Ecran_Histo_press();
void Ecran_Histo_hygro();

void lcd_send_cmd(char cmd);
void lcd_send_data(char data);
