enum combos {
  NAVSTRG,//
  ACCENT,
  BRO,
  BRO2,
  BRC,
  BRC2,
  SBRO,
  SBRC,
  CBRO,
  CBRC,
  TRO,
  TRC,
  SLA,
  SLA2,
  BSLA,
  QUIT,
  MINUS,
  ALTTAB,
  //ALTBTAB,
  WINGUI,
  ESCAPING,
  DELETING,
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define and use this instead!

const uint16_t PROGMEM navstrg[] = {KC_A, KC_B, COMBO_END};
const uint16_t PROGMEM accent[] = {KC_A, KC_X, COMBO_END};
const uint16_t PROGMEM bro[] = {KC_H, KC_L, COMBO_END};
const uint16_t PROGMEM bro2[] = {KC_7, KC_8, COMBO_END};
const uint16_t PROGMEM brc[] = {KC_L, KC_M, COMBO_END};
const uint16_t PROGMEM brc2[] = {KC_8, KC_9, COMBO_END};
const uint16_t PROGMEM sbro[] = {S(KC_H), S(KC_L), COMBO_END};
const uint16_t PROGMEM sbrc[] = {S(KC_L), S(KC_M), COMBO_END};
const uint16_t PROGMEM cbro[] = {FN_NO, FN_LCKSCRN, COMBO_END};
const uint16_t PROGMEM cbrc[] = {FN_LCKSCRN, FN_ROTATE, COMBO_END};
const uint16_t PROGMEM tro[] = {FN_PRINT, FN_NO, COMBO_END};
const uint16_t PROGMEM trc[] = {FN_ROTATE, FN_TXTSHT, COMBO_END};
const uint16_t PROGMEM sla[] = {KC_B, KC_N, COMBO_END};
const uint16_t PROGMEM sla2[] = {TD(STARPIPEPM), KC_4, COMBO_END};
const uint16_t PROGMEM bsla[] = {S(KC_B), S(KC_N), COMBO_END};
const uint16_t PROGMEM quit[] = {KC_N, KC_R, TD(ESZET), KC_G, COMBO_END};
const uint16_t PROGMEM minus[] = {DE_Z, MO(SHIF), COMBO_END};
const uint16_t PROGMEM alttab[] = {KC_R, TD(ESZET), COMBO_END};
//const uint16_t PROGMEM altbtab[] = {KC_H, KC_L, COMBO_END};
const uint16_t PROGMEM wingui[] = {KC_C, KC_T, KC_I, KC_E, COMBO_END};
const uint16_t PROGMEM escaping[] = {KC_J, KC_D, COMBO_END};
const uint16_t PROGMEM deleting[] = {KC_M, KC_W, COMBO_END};

combo_t key_combos[] = {
    [NAVSTRG] = COMBO(navstrg, KC_LCTL),
    [ACCENT] = COMBO(accent, KC_EQL),
    [BRO] = COMBO(bro, LSFT(KC_8)),
    [BRO2] = COMBO(bro2, LSFT(KC_8)),
    [BRC] = COMBO(brc, LSFT(KC_9)),
    [BRC2] = COMBO(brc2, LSFT(KC_9)),
    [SBRO] = COMBO(sbro, RALT(KC_8)),
    [SBRC] = COMBO(sbrc, RALT(KC_9)),
    [CBRO] = COMBO(cbro, RALT(KC_7)),
    [CBRC] = COMBO(cbrc, RALT(KC_0)),
    [TRO] = COMBO(tro, KC_NUBS),
    [TRC] = COMBO(trc, LSFT(KC_NUBS)),
    [SLA] = COMBO(sla, LSFT(KC_7)),
    [SLA2] = COMBO(sla2, LSFT(KC_7)),
    [BSLA] = COMBO(bsla, RALT(KC_MINS)),
    [QUIT] = COMBO(quit, LALT(KC_F4)),
    [MINUS] = COMBO(minus, KC_SLSH),
    [ALTTAB] = COMBO(alttab, ALT_TAB),
    //[ALTBTAB] = COMBO(altbtab, ALT_BTAB),
    [ESCAPING] = COMBO(escaping, KC_ESC),
    [WINGUI] = COMBO(wingui, KC_LGUI),
    [DELETING] = COMBO(deleting, KC_DEL)
};