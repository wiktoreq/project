#ifndef DATA_H
#define DATA_H

#include <QString>
#include <vector>

struct letter
{
    QChar c;
    int freq = 0;
};

struct digram
{
    QString digram;
    double freq = 0;
};

struct trigram
{
    QString trigram;
    double freq = 0;
};

struct frequency
{
    QChar c;
    double freq;
};

inline const QString polish = "aąbcćdeęfghijklłmnoópqrsśtuvwxyzźż";
inline const QString english = "abcdefghijklmnńopqrstuvwxyz";

const std::vector<frequency> POLISH_LETTER_STATS = {
    { QChar('a'), 8.91 },
    { QChar('i'), 8.21 },
    { QChar('o'), 7.75 },
    { QChar('e'), 7.66 },
    { QChar('z'), 5.64 },
    { QChar('n'), 5.52 },
    { QChar('r'), 4.69 },
    { QChar('w'), 4.65 },
    { QChar('s'), 4.32 },
    { QChar('t'), 3.98 },
    { QChar('c'), 3.96 },
    { QChar('y'), 3.76 },
    { QChar('k'), 3.51 },
    { QChar('d'), 3.25 },
    { QChar('p'), 3.13 },
    { QChar('m'), 2.80 },
    { QChar('u'), 2.50 },
    { QChar('j'), 2.28 },
    { QChar('l'), 2.10 },
    { QChar(u'ł'), 1.82 },
    { QChar('b'), 1.47 },
    { QChar('g'), 1.42 },
    { QChar(u'ę'), 1.11 },
    { QChar('h'), 1.08 },
    { QChar(u'ą'), 0.99 },
    { QChar(u'ó'), 0.85 },
    { QChar(u'ż'), 0.83 },
    { QChar(u'ś'), 0.66 },
    { QChar(u'ć'), 0.40 },
    { QChar('f'), 0.30 },
    { QChar(u'ń'), 0.20 },
    { QChar('q'), 0.14 },
    { QChar(u'ź'), 0.06 },
    { QChar('v'), 0.04 },
    { QChar('x'), 0.02 }
};

const std::vector<frequency> ENGLISH_LETTER_STATS = {
    { QChar('e'), 12.702 },
    { QChar('t'), 9.056 },
    { QChar('a'), 8.496 },
    { QChar('o'), 7.507 },
    { QChar('i'), 6.966 },
    { QChar('n'), 6.749 },
    { QChar('s'), 6.327 },
    { QChar('h'), 6.094 },
    { QChar('r'), 5.987 },
    { QChar('d'), 4.253 },
    { QChar('l'), 4.025 },
    { QChar('c'), 2.782 },
    { QChar('u'), 2.758 },
    { QChar('m'), 2.406 },
    { QChar('w'), 2.360 },
    { QChar('f'), 2.228 },
    { QChar('g'), 2.015 },
    { QChar('y'), 1.974 },
    { QChar('p'), 1.929 },
    { QChar('b'), 1.492 },
    { QChar('v'), 0.978 },
    { QChar('k'), 0.772 },
    { QChar('j'), 0.153 },
    { QChar('x'), 0.150 },
    { QChar('q'), 0.095 },
    { QChar('z'), 0.074 }
};

const std::vector<digram> ENGLISH_DIGRAM_STATS = {
    { QStringLiteral("TH"), 2.71 },
    { QStringLiteral("HE"), 2.33 },
    { QStringLiteral("IN"), 2.03 },
    { QStringLiteral("ER"), 1.78 },
    { QStringLiteral("AN"), 1.61 },
    { QStringLiteral("RE"), 1.41 },
    { QStringLiteral("ES"), 1.32 },
    { QStringLiteral("ON"), 1.32 },
    { QStringLiteral("ST"), 1.25 },
    { QStringLiteral("NT"), 1.17 },
    { QStringLiteral("EN"), 1.13 },
    { QStringLiteral("AT"), 1.12 },
    { QStringLiteral("ED"), 1.08 },
    { QStringLiteral("ND"), 1.07 },
    { QStringLiteral("TO"), 1.07 },
    { QStringLiteral("OR"), 1.06 },
    { QStringLiteral("EA"), 1.00 },
    { QStringLiteral("TI"), 0.99 },
    { QStringLiteral("AR"), 0.98 },
    { QStringLiteral("TE"), 0.98 },
    { QStringLiteral("NG"), 0.89 },
    { QStringLiteral("AL"), 0.88 },
    { QStringLiteral("IT"), 0.88 },
    { QStringLiteral("AS"), 0.87 },
    { QStringLiteral("IS"), 0.86 },
    { QStringLiteral("HA"), 0.83 },
    { QStringLiteral("ET"), 0.76 },
    { QStringLiteral("SE"), 0.73 },
    { QStringLiteral("OU"), 0.72 },
    { QStringLiteral("OF"), 0.71 }
};

const std::vector<trigram> ENGLISH_TRIGRAM_STATS = {
    { QStringLiteral("THE"), 1.81 },
    { QStringLiteral("AND"), 0.73 },
    { QStringLiteral("ING"), 0.72 },
    { QStringLiteral("ENT"), 0.42 },
    { QStringLiteral("ION"), 0.42 },
    { QStringLiteral("HER"), 0.36 },
    { QStringLiteral("FOR"), 0.34 },
    { QStringLiteral("THA"), 0.33 },
    { QStringLiteral("NTH"), 0.33 },
    { QStringLiteral("INT"), 0.32 },
    { QStringLiteral("ERE"), 0.31 },
    { QStringLiteral("TIO"), 0.31 },
    { QStringLiteral("TER"), 0.30 },
    { QStringLiteral("EST"), 0.28 },
    { QStringLiteral("ERS"), 0.28 },
    { QStringLiteral("ATI"), 0.26 },
    { QStringLiteral("HAT"), 0.26 },
    { QStringLiteral("ATE"), 0.25 },
    { QStringLiteral("ALL"), 0.25 },
    { QStringLiteral("ETH"), 0.24 },
    { QStringLiteral("HES"), 0.24 },
    { QStringLiteral("VER"), 0.24 },
    { QStringLiteral("HIS"), 0.24 },
    { QStringLiteral("OFT"), 0.22 },
    { QStringLiteral("ITH"), 0.21 },
    { QStringLiteral("FTH"), 0.21 },
    { QStringLiteral("STH"), 0.21 },
    { QStringLiteral("OTH"), 0.21 },
    { QStringLiteral("RES"), 0.21 },
    { QStringLiteral("ONT"), 0.20 }
};

const std::vector<digram> POLISH_DIGRAM_STATS = {
    { QStringLiteral("IE"), 2.31 },
    { QStringLiteral("NI"), 1.79 },
    { QStringLiteral("OW"), 1.27 },
    { QStringLiteral("ST"), 1.23 },
    { QStringLiteral("NA"), 1.20 },
    { QStringLiteral("AN"), 1.13 },
    { QStringLiteral("PO"), 1.05 },
    { QStringLiteral("CH"), 0.99 },
    { QStringLiteral("CZ"), 0.99 },
    { QStringLiteral("RZ"), 0.93 },
    { QStringLiteral("ZE"), 0.93 },
    { QStringLiteral("RA"), 0.86 },
    { QStringLiteral("RO"), 0.84 },
    { QStringLiteral("WA"), 0.84 },
    { QStringLiteral("IA"), 0.83 },
    { QStringLiteral("ZA"), 0.79 },
    { QStringLiteral("WI"), 0.79 },
    { QStringLiteral("OD"), 0.78 },
    { QStringLiteral("MI"), 0.78 },
    { QStringLiteral("AR"), 0.76 },
    { QStringLiteral("TA"), 0.76 },
    { QStringLiteral("ER"), 0.76 },
    { QStringLiteral("PR"), 0.75 },
    { QStringLiteral("ON"), 0.73 },
    { QStringLiteral("KI"), 0.71 },
    { QStringLiteral("EN"), 0.70 },
    { QStringLiteral("KO"), 0.69 },
    { QStringLiteral("EJ"), 0.68 },
    { QStringLiteral("ZY"), 0.67 },
    { QStringLiteral("ES"), 0.64 }
};

const std::vector<trigram> POLISH_TRIGRAM_STATS = {
    { QStringLiteral("NIE"), 0.79 },
    { QStringLiteral("RZE"), 0.47 },
    { QStringLiteral("PRZ"), 0.42 },
    { QStringLiteral("OWA"), 0.40 },
    { QStringLiteral("EGO"), 0.40 },
    { QStringLiteral("STA"), 0.40 },
    { QStringLiteral("YCH"), 0.36 },
    { QStringLiteral("DZI"), 0.36 },
    { QStringLiteral("ANI"), 0.33 },
    { QStringLiteral("WIE"), 0.31 },
    { QStringLiteral("NIA"), 0.30 },
    { QStringLiteral("ENI"), 0.29 },
    { QStringLiteral("SIĘ"), 0.29 },
    { QStringLiteral("SKI"), 0.28 },
    { QStringLiteral("IEJ"), 0.28 },
    { QStringLiteral("KIE"), 0.28 },
    { QStringLiteral("WAN"), 0.26 },
    { QStringLiteral("IER"), 0.26 },
    { QStringLiteral("RZY"), 0.25 },
    { QStringLiteral("MIE"), 0.24 },
    { QStringLiteral("OST"), 0.23 },
    { QStringLiteral("ŚCI"), 0.23 },
    { QStringLiteral("CZN"), 0.22 },
    { QStringLiteral("ACH"), 0.22 },
    { QStringLiteral("EST"), 0.21 },
    { QStringLiteral("OWI"), 0.20 },
    { QStringLiteral("ZIE"), 0.19 },
    { QStringLiteral("AMI"), 0.19 },
    { QStringLiteral("JES"), 0.18 },
    { QStringLiteral("NYC"), 0.18 }
};


#endif // DATA_H
