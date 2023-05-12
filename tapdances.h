typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

enum {
    KQ,
    NAVNUM,
    COMMQ,
    VEXCL,
    ESZET,
    SHIKQ,
    STARPIPEPM,
    YMINS,
    ADIAAT,
    OE,
    UE,
    SHIOE,
    SHIUE,
    EURDOLLPARA,
    ENTIST,
    PLUSIST,
    PERDEGTILD,
};

td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else return TD_UNKNOWN;
}

static td_tap_t xtap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void navnum(qk_tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case TD_SINGLE_TAP: layer_on(NAV); break;
        case TD_SINGLE_HOLD: layer_on(NAV); break;
        case TD_DOUBLE_TAP: layer_on(NUM); break;
        case TD_DOUBLE_HOLD: layer_on(NUM); break;
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_NO); register_code(KC_NO); break;
        default: break;
    }
}

void navnum_res(qk_tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_NO); break;
        case TD_SINGLE_HOLD: layer_off(NAV); break;
        case TD_DOUBLE_TAP: unregister_code(KC_NO); break;
        case TD_DOUBLE_HOLD: layer_off(NUM); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_NO); break;
        default: break;
    }
    xtap_state.state = TD_NONE;
}

void vexcl(qk_tap_dance_state_t *state, void *user_data) {
if (state->count == 1) {
  SEND_STRING ("v");
  reset_tap_dance (state); }
else if (state->count == 2) {
    SEND_STRING(SS_LSFT(SS_TAP(X_1))); }
}

void commq(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
  SEND_STRING (",");
  reset_tap_dance (state); }
else if (state->count == 2) {
    SEND_STRING(SS_LSFT(SS_TAP(X_MINS)));}
}

void eszet(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
  SEND_STRING ("s");
  reset_tap_dance (state); }
    else if (state->count == 2) {
  SEND_STRING ("ss");
  reset_tap_dance (state); }
else if (state->count == 3) {
    SEND_STRING(SS_TAP(X_MINS));}
}

void shikq(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
  SEND_STRING(SS_LSFT(SS_TAP(X_K)));
  reset_tap_dance (state); }
else if (state->count == 2) {
    SEND_STRING(SS_LSFT(SS_TAP(X_Q)));}
}

void starpipepm(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
  SEND_STRING(SS_LSFT(SS_TAP(X_RBRC)));
  reset_tap_dance (state); }
    else if (state->count == 2) {
  SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_L))));
  reset_tap_dance (state); }
    else if (state->count == 3) {
  SEND_STRING(SS_RALT(SS_TAP(X_NUBS)));
  reset_tap_dance (state); }
else if (state->count == 4) {
    register_code(KC_LALT);
    tap_code(KC_KP_2);
    tap_code(KC_KP_4);
    tap_code(KC_KP_1);
    unregister_code(KC_LALT);
    }
}

void adiaat(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
  SEND_STRING(SS_TAP(X_QUOT));
  reset_tap_dance (state); }
    else if (state->count == 2) {
  SEND_STRING(SS_RALT(SS_TAP(X_Q)));}
}

void oe(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
  SEND_STRING(SS_TAP(X_SCLN));
  reset_tap_dance (state); }
    else if (state->count == 2) {
    register_code(KC_LALT);
    tap_code(KC_KP_0);
    tap_code(KC_KP_3);
    tap_code(KC_KP_3);
    tap_code(KC_KP_7);
    unregister_code(KC_LALT);
    }
}

void ue(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
  SEND_STRING(SS_TAP(X_LBRC));
  reset_tap_dance (state); }
    else if (state->count == 2) {
    register_code(KC_LALT);
    tap_code(KC_KP_0);
    tap_code(KC_KP_3);
    tap_code(KC_KP_6);
    tap_code(KC_KP_9);
    unregister_code(KC_LALT);
    }
}

void shioe(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
  SEND_STRING(SS_LSFT(SS_TAP(X_SCLN)));
  reset_tap_dance (state); }
    else if (state->count == 3) {
    register_code(KC_LALT);
    tap_code(KC_KP_0);
    tap_code(KC_KP_3);
    tap_code(KC_KP_3);
    tap_code(KC_KP_6);
    unregister_code(KC_LALT);
    }
}

void shiue(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
  SEND_STRING(SS_LSFT(SS_TAP(X_LBRC)));
  reset_tap_dance (state); }
    else if (state->count == 3) {
    register_code(KC_LALT);
    tap_code(KC_KP_0);
    tap_code(KC_KP_3);
    tap_code(KC_KP_6);
    tap_code(KC_KP_8);
    unregister_code(KC_LALT);
    }
}

void eurdollpara(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
  SEND_STRING(SS_RALT(SS_TAP(X_E))); //€
  reset_tap_dance (state); }
    else if (state->count == 2) {
  SEND_STRING(SS_LSFT(SS_TAP(X_4))); //$
  reset_tap_dance (state); }
    else if (state->count == 3) {
  SEND_STRING(SS_LSFT(SS_TAP(X_3))); //§
    }
}

void entist(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
  SEND_STRING(SS_TAP(X_ENTER));
  reset_tap_dance (state); }
    else if (state->count == 2) {
  SEND_STRING(SS_LSFT(SS_TAP(X_0)));
    }
}

void plusist(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
  SEND_STRING(SS_TAP(X_RBRC));
  reset_tap_dance (state); }
    else if (state->count == 2) {
  SEND_STRING(SS_LSFT(SS_TAP(X_0)));
    }
}

void perdegtild(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
  SEND_STRING(SS_LSFT(SS_TAP(X_5))); //%
  reset_tap_dance (state); }
    else if (state->count == 2) {
  SEND_STRING(SS_LSFT(SS_TAP(X_GRV))); //°
  reset_tap_dance (state); }
    else if (state->count == 3) {
  SEND_STRING(SS_RALT(SS_TAP(X_RBRC))); //~
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [NAVNUM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, navnum, navnum_res),
    [KQ] = ACTION_TAP_DANCE_DOUBLE(KC_K, KC_Q),
    [SHIKQ] = ACTION_TAP_DANCE_FN(shikq),
    [VEXCL] = ACTION_TAP_DANCE_FN(vexcl),
    [COMMQ] = ACTION_TAP_DANCE_FN(commq),
    [ESZET] = ACTION_TAP_DANCE_FN(eszet),
    [STARPIPEPM] = ACTION_TAP_DANCE_FN(starpipepm),
    [YMINS] = ACTION_TAP_DANCE_DOUBLE(KC_Z, KC_SLSH),
    [ADIAAT] = ACTION_TAP_DANCE_FN(adiaat),
    [OE] = ACTION_TAP_DANCE_FN(oe),
    [UE] = ACTION_TAP_DANCE_FN(ue),
    [SHIOE] = ACTION_TAP_DANCE_FN(shioe),
    [SHIUE] = ACTION_TAP_DANCE_FN(shiue),
    [EURDOLLPARA] = ACTION_TAP_DANCE_FN(eurdollpara),
    [ENTIST] = ACTION_TAP_DANCE_FN(entist),
    [PLUSIST] = ACTION_TAP_DANCE_FN(plusist),
    [PERDEGTILD] = ACTION_TAP_DANCE_FN(perdegtild),
};