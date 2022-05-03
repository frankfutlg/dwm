static const char black_0[]	= "#161320";
static const char black_1[]	= "#1A1826";
static const char black_2[]	= "#1E1E2E";
static const char black_3[]	= "#302D41";
static const char black_4[]	= "#575268";
static const char gray_0[]	= "#6E6C7E";
static const char gray_1[]	= "#988BA2";
static const char gray_2[]	= "#C3BAC6";
static const char white[]	= "#D9E0EE";
static const char lavender[]	= "#C9CBFF";
static const char rosewater[]	= "#F5E0DC";
static const char flamingo[]	= "#F2CDCD";
static const char mauve[]	= "#DDB6F2";
static const char pink[]	= "#F5C2E7";
static const char maroon[]	= "#E8A2AF";
static const char red[]		= "#F28FAD";
static const char peach[]	= "#F8BD96";
static const char yellow[]	= "#FAE3B0";
static const char green[]	= "#ABE9B3";
static const char teal[]	= "#B5E8E0";
static const char blue[]	= "#96CDFB";
static const char sky[]		= "#89DCEB";

static const char *colors[][3]      = {
	//                 fg       	bg        	border   
	[SchemeNorm]   = { gray_0,	black_0,	black_0 },
	[SchemeSel]    = { pink,	black_0,	blue	},		
	[SchemeTag]    = { gray_0,	black_0,	black_0 },
    	[SchemeTag1]   = { blue,	black_0,	black_0 },
    	[SchemeTag2]   = { green,	black_0,	black_0	},
    	[SchemeTag3]   = { yellow,	black_0,	black_0 },
    	[SchemeTag4]   = { red,		black_0,	black_0 },
    	[SchemeTag5]   = { pink,	black_0,	black_0 },
	[SchemeLayout] = { lavender,	black_0,	black_0 },
	[SchemeTitle]  = { lavender,	black_0,	pink	},
};
