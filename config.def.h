/* See LICENSE file for copyright and license details. */
//#define TERMINAL "st"

/* Appearance */
static const unsigned int borderpx  = 2;        /* border pixel size of windows */
static const unsigned int gappx     = 5;        /* gaps size between windows */
//static const Gap default_gap              = {.isgap = 1, .realgap = 10, .gappx = 10};
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "FiraCode Nerd Font:pixelsize=11:antialias=true:autohint=true", "CaskaydiaCove Nerd Font Mono:pixelsize=10:antialias=true:autohint=true", "monospace:size=8" };
static const char dmenufont[]             = "FiraCode Nerd Font:pixelsize=11:antialias=true:autohint=true";
//static char *font = "FiraCode Nerd Font:pixelsize=12:antialias=true:autohint=true";

static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const char *colors[][5]          = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};

/* /1* Added but Unused Colors *1/ */
/* static const char col_matrix_green[]      = "#00FF41"; */
/* static const char col_matrix_green_dark[] = "#008F11"; */
/* static const char col_matrix_black[]      = "#222222"; */
/* static const char *colors[][3]            = { */
/* 	/1*               fg         bg         border   *1/ */
/* 	[SchemeNorm] = { col_matrix_green_dark, col_matrix_black, col_matrix_black}, */
/* 	[SchemeSel]  = { col_matrix_green,      col_matrix_black, col_matrix_black }, */
/* }; */


/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
/* static const char *tags[] = { "", "", "", "", "", "", "", "", "" }; */

// https://dwm.suckless.org/customisation/rules/
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class         instance       title            tags mask     iscentered     isfloating   monitor */
	{ "Gimp",        NULL,          NULL,            0,            0,             1,           -1 },
	{ "st-256color", "st-256color", "pulsemixer",    0,            1,             1,           -1 },
	{ "st-256color", "st-256color", "bc",            0,            1,             1,           -1 },
	{ "mpv",         "mpv",         "mpvfloat",      0,            1,             1,           -1 },
    { "firefox",     NULL,           NULL,           1 << 0,       0,             -1           -1 },
    { "Telegram",    NULL,           NULL,           1 << 2,       1,             1            -1 },
};

    /* layout(s) */
static const float mfact     = 0.5; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
//static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },
/* #define STACKKEYS(MOD,ACTION) \ */
/* 	{ MOD,	                        XK_j,	ACTION##stack,	{.i = INC(+1) } }, \ */
/* 	{ MOD,	                        XK_k,	ACTION##stack,	{.i = INC(-1) } }, \ */
/* 	{ MOD,                          XK_v,   ACTION##stack,  {.i = 0 } }, \ */

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

#include "shiftview.c"
/* static char *endx[] = { "/bin/sh", "-c", "endx", "externalpipe", null }; */

/* commands */
static char dmenumon[2]            = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *calccmd[]       = { "st", "-e", "bc -l", NULL };
/* static const char *camtogglecmd[]  = { "camtoggle", NULL }; */
/* static const char *dmenucmd[]      = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_matrix_black, "-nf", col_matrix_green_dark, "-sb", col_matrix_black, "-sf", col_matrix_green, NULL }; */
static const char *dmenucmd[]      = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
/* static const char *pulsemixercmd[] = { "st", "-e", "pulsemixer", NULL }; */
static const char *topcmd[]        = { "st", "-n", "top", "-e", "htop", NULL };
static const char *mailcmd[]       = { "st", "-e", "neomutt", NULL };
static const char *filecmd[]       = { "st", "-e", "lfub", NULL };
static const char *termcmd[]       = { "st", NULL };
static const char *timecmd[]       = { "popinfo2", NULL };

static const char *upvol[]   = { "amixer", "-q", "set", "Master", "5%+", "unmute", NULL };
static const char *downvol[] = { "amixer", "-q", "set", "Master", "5%-", "unmute", NULL };
static const char *mutevol[] = { "amixer", "-q", "set", "Master", "toggle", NULL };

/* /1* commands *1/ */
/* static char dmenumon[2] = "0"; /1* component of dmenucmd, manipulated in spawn() *1/ */
/* static const char *dmenucmd[] = { "dmenu_run", "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL }; */
/* static const char *termcmd[]  = { "st", NULL }; */
/* static const char *filecmd[] = { "st", "-e", "lfub", NULL }; */
/* static const char *mailcmd[] = { "st", "-e", "neomutt", NULL }; */
/* static const char *topcmd[]  = { "st", "-e", "htop", NULL }; */
/* /1* Volume controls *1/ */
/* static const char *upvol[]   = { "amixer", "-q", "set", "Master", "5%+", "unmute", NULL }; */
/* static const char *downvol[] = { "amixer", "-q", "set", "Master", "5%-", "unmute", NULL }; */
/* static const char *mutevol[] = { "amixer", "-q", "set", "Master", "toggle", NULL }; */

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_p,      spawn,          SHCMD("passmenu") },
	{ MODKEY|ShiftMask,             XK_n,      spawn,          SHCMD("st -e nvim -c VimwikiIndex") },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	/* { MODKEY,                       XK_Return, zoom,           {0} }, */
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  zoom,           {0} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
    /* { MODKEY,                       XK_minus,  setgaps,        {.i = -5 } }, */
	/* { MODKEY,                       XK_equal,  setgaps,        {.i = +5 } }, */
	/* { MODKEY|ShiftMask,             XK_minus,  setgaps,        {.i = GAP_RESET } }, */
	/* { MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = GAP_TOGGLE} }, */
    { MODKEY,                       XK_minus,  spawn,          {.v = downvol} },
    { MODKEY,                       XK_equal,  spawn,          {.v = upvol } },
	{ MODKEY|ShiftMask,             XK_equal,  spawn,          {.v = mutevol } },
    { MODKEY,                       XK_z,      zoom,           {0} },
    { MODKEY|ShiftMask,             XK_z,      setgaps,        {.i = -5 } },
    { MODKEY|ShiftMask,             XK_x,      setgaps,        {.i = +5 } },

	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },

	/* isaks keys */
    /* { MODKEY|ShiftMask,             XK_e,      spawn,          SHCMD("st -e watch -p -t -n .5 'grep MHz /proc/cpuinfo'") }, */
    { MODKEY,                       XK_e,      spawn,          {.v = mailcmd } },
	{ MODKEY|ShiftMask,             XK_e,      spawn,          {.v = filecmd } },
    { MODKEY,                       XK_r,      spawn,          {.v = topcmd } },
    { MODKEY|ShiftMask,             XK_r,       spawn,          SHCMD("st -e watch -p -t -n .5 'grep MHz /proc/cpuinfo'") },
    { MODKEY,                       XK_Escape,  spawn,          SHCMD("slock") },
	{ MODKEY|ShiftMask,             XK_w,      spawn,          SHCMD("$BROWSER") },
	{ MODKEY|ShiftMask,             XK_g,      spawn,          SHCMD("st -e swallow $BROWSER -p Gooner") },
	{ MODKEY,                       XK_c,      spawn,          {.v = calccmd } },
	{ MODKEY|ShiftMask,             XK_t,      spawn,          {.v = timecmd} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
