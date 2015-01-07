﻿using System;

namespace NativeScript.TestFixtures
{
    public enum EmptyEnum
    {
    }

    public enum SimpleEnum
    {
        Value1 = -1,
        Value2,
        Value3,
    }

    // [Flags] must not be present if enum is int; required if enum is uint

    public enum Int32Enum : int
    {
        MinValue = int.MinValue,
        MaxValue = int.MaxValue,
    }

    [Flags]
    public enum UInt32Enum : uint
    {
        MinValue = uint.MinValue,
        MaxValue = uint.MaxValue,
    }

    public enum ManyMembersEnum
    {
        V000,
        V001,
        V002,
        V003,
        V004,
        V005,
        V006,
        V007,
        V008,
        V009,
        V010,
        V011,
        V012,
        V013,
        V014,
        V015,
        V016,
        V017,
        V018,
        V019,
        V020,
        V021,
        V022,
        V023,
        V024,
        V025,
        V026,
        V027,
        V028,
        V029,
        V030,
        V031,
        V032,
        V033,
        V034,
        V035,
        V036,
        V037,
        V038,
        V039,
        V040,
        V041,
        V042,
        V043,
        V044,
        V045,
        V046,
        V047,
        V048,
        V049,
        V050,
        V051,
        V052,
        V053,
        V054,
        V055,
        V056,
        V057,
        V058,
        V059,
        V060,
        V061,
        V062,
        V063,
        V064,
        V065,
        V066,
        V067,
        V068,
        V069,
        V070,
        V071,
        V072,
        V073,
        V074,
        V075,
        V076,
        V077,
        V078,
        V079,
        V080,
        V081,
        V082,
        V083,
        V084,
        V085,
        V086,
        V087,
        V088,
        V089,
        V090,
        V091,
        V092,
        V093,
        V094,
        V095,
        V096,
        V097,
        V098,
        V099,
        V100,
        V101,
        V102,
        V103,
        V104,
        V105,
        V106,
        V107,
        V108,
        V109,
        V110,
        V111,
        V112,
        V113,
        V114,
        V115,
        V116,
        V117,
        V118,
        V119,
        V120,
        V121,
        V122,
        V123,
        V124,
        V125,
        V126,
        V127,
        V128,
        V129,
        V130,
        V131,
        V132,
        V133,
        V134,
        V135,
        V136,
        V137,
        V138,
        V139,
        V140,
        V141,
        V142,
        V143,
        V144,
        V145,
        V146,
        V147,
        V148,
        V149,
        V150,
        V151,
        V152,
        V153,
        V154,
        V155,
        V156,
        V157,
        V158,
        V159,
        V160,
        V161,
        V162,
        V163,
        V164,
        V165,
        V166,
        V167,
        V168,
        V169,
        V170,
        V171,
        V172,
        V173,
        V174,
        V175,
        V176,
        V177,
        V178,
        V179,
        V180,
        V181,
        V182,
        V183,
        V184,
        V185,
        V186,
        V187,
        V188,
        V189,
        V190,
        V191,
        V192,
        V193,
        V194,
        V195,
        V196,
        V197,
        V198,
        V199,
        V200,
        V201,
        V202,
        V203,
        V204,
        V205,
        V206,
        V207,
        V208,
        V209,
        V210,
        V211,
        V212,
        V213,
        V214,
        V215,
        V216,
        V217,
        V218,
        V219,
        V220,
        V221,
        V222,
        V223,
        V224,
        V225,
        V226,
        V227,
        V228,
        V229,
        V230,
        V231,
        V232,
        V233,
        V234,
        V235,
        V236,
        V237,
        V238,
        V239,
        V240,
        V241,
        V242,
        V243,
        V244,
        V245,
        V246,
        V247,
        V248,
        V249,
        V250,
        V251,
        V252,
        V253,
        V254,
        V255,
        V256,
        V257,
        V258,
        V259,
        V260,
        V261,
        V262,
        V263,
        V264,
        V265,
        V266,
        V267,
        V268,
        V269,
        V270,
        V271,
        V272,
        V273,
        V274,
        V275,
        V276,
        V277,
        V278,
        V279,
        V280,
        V281,
        V282,
        V283,
        V284,
        V285,
        V286,
        V287,
        V288,
        V289,
        V290,
        V291,
        V292,
        V293,
        V294,
        V295,
        V296,
        V297,
        V298,
        V299,
        V300,
        V301,
        V302,
        V303,
        V304,
        V305,
        V306,
        V307,
        V308,
        V309,
        V310,
        V311,
        V312,
        V313,
        V314,
        V315,
        V316,
        V317,
        V318,
        V319,
        V320,
        V321,
        V322,
        V323,
        V324,
        V325,
        V326,
        V327,
        V328,
        V329,
        V330,
        V331,
        V332,
        V333,
        V334,
        V335,
        V336,
        V337,
        V338,
        V339,
        V340,
        V341,
        V342,
        V343,
        V344,
        V345,
        V346,
        V347,
        V348,
        V349,
        V350,
        V351,
        V352,
        V353,
        V354,
        V355,
        V356,
        V357,
        V358,
        V359,
        V360,
        V361,
        V362,
        V363,
        V364,
        V365,
        V366,
        V367,
        V368,
        V369,
        V370,
        V371,
        V372,
        V373,
        V374,
        V375,
        V376,
        V377,
        V378,
        V379,
        V380,
        V381,
        V382,
        V383,
        V384,
        V385,
        V386,
        V387,
        V388,
        V389,
        V390,
        V391,
        V392,
        V393,
        V394,
        V395,
        V396,
        V397,
        V398,
        V399,
        V400,
        V401,
        V402,
        V403,
        V404,
        V405,
        V406,
        V407,
        V408,
        V409,
        V410,
        V411,
        V412,
        V413,
        V414,
        V415,
        V416,
        V417,
        V418,
        V419,
        V420,
        V421,
        V422,
        V423,
        V424,
        V425,
        V426,
        V427,
        V428,
        V429,
        V430,
        V431,
        V432,
        V433,
        V434,
        V435,
        V436,
        V437,
        V438,
        V439,
        V440,
        V441,
        V442,
        V443,
        V444,
        V445,
        V446,
        V447,
        V448,
        V449,
        V450,
        V451,
        V452,
        V453,
        V454,
        V455,
        V456,
        V457,
        V458,
        V459,
        V460,
        V461,
        V462,
        V463,
        V464,
        V465,
        V466,
        V467,
        V468,
        V469,
        V470,
        V471,
        V472,
        V473,
        V474,
        V475,
        V476,
        V477,
        V478,
        V479,
        V480,
        V481,
        V482,
        V483,
        V484,
        V485,
        V486,
        V487,
        V488,
        V489,
        V490,
        V491,
        V492,
        V493,
        V494,
        V495,
        V496,
        V497,
        V498,
        V499,
        V500,
        V501,
        V502,
        V503,
        V504,
        V505,
        V506,
        V507,
        V508,
        V509,
        V510,
        V511
    }
}