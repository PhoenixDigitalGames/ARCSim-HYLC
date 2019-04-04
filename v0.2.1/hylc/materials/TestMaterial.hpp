// #ifndef _TESTMATERIAL_HPP_
// #define _TESTMATERIAL_HPP_
//
// #include "BaseMaterial.hpp"
// #include <vector>
//
// namespace hylc {
// class TestMaterial : public BaseMaterial {
// public:
//   TestMaterial() {
//     s = 1;         // 1e-2;
//     double sk = 1; // 1e2; // debug, if bigger less curvy stuff
//     double se = 1; // 1e2; // debug, if bigger less curvy stuff
//
//     // NOTE energy from this is off by factor of 0.85*0.85 ish
//     // because i forgot to scale the ref area with proto
//     // m_C = {-4.700194616233,      -5.37199649556925,    6.07544107819065,
//     //        3.34509809168707,     -0.551509389317062,   0.46928393375905,
//     //        -4.70455827320207,    0.0353578411971718,   0.103343055539766,
//     //        0.00120629726395653,  0.195057520109849,    1.78920787179131,
//     //        3.91330245186814,     3.05128841702532,     -0.560075395101677,
//     //        0.552456271015256,    3.33144826838135,     0.0163911521599623,
//     //        0.235517324940807,    -0.00118848480256068, 0.0017881990202135,
//     //        0.105397494644102,    0.0125797205563788,   0.170892451855713,
//     //        -0.00100864927402942, 0.084245846297178,    -1.12063033182466,
//     //        0.0347196676295963,   0.22307826917786,     -0.00474923578610595,
//     //        0.000677340430722436};
//     // m_ekmean = {1.250000002847,       -4.05699995820186e-11,
//     //             1.250000002027,       1.70530256582424e-15,
//     //             -5.6843418860808e-16, -4.54747350886464e-15};
//     // m_ekstd = {se * 0.43736469869565,  se * 0.408207051975081,
//     //            se * 0.437364698392629, sk * 291.111346991829,
//     //            sk * 162.453284671786,  sk * 290.987334018003};
//     // density = 0.893948789;
//
//     // new solver, satin (woven)
//     // m_C = {-19.5106226137749, -14.8887513405194,   60.2419158678999,
//     //        75.5036306591303,  -11.1008994148511,   2.36323637514545,
//     //        103.147288358499,  -0.0670538692378278, 7.8256956609113,
//     //        0.180953716991772, 6.37334296035155,    103.531242147118,
//     //        53.145286880162,   73.928764417288,     -10.9835832744031,
//     //        2.49409591139069,  73.5177437543663,    -7.48497251975264,
//     //        4.22951211666752,  -0.380170970542495,  0.581650383964113,
//     //        -75.6509059738394, 3.439161675968,      -4.89753589103281,
//     //        -3.84738121401991, 5.48119938419373,    -35.4030497115099,
//     //        6.02752973876084,  3.9254199420686,     0.604897190191608,
//     //        0.58872289014227};
//     // m_ekmean = {1.150000002605, -6.62100052561954e-11, 1.150000002188,
//     //             1.490847548,    3.41060513164848e-15,  -13.509762429};
//     // m_ekstd = {se*0.495679991839402, se*0.408207052029022,
//     // se*0.495679991670778,
//     //            sk*352.821559575896,  sk*181.093921435173,
//     //            sk*352.535219342467};
//     // density = 1.0109828039e+00;
//
//     // new solver, cartridge (knit)
//     m_C = {284.036603956062,   1727.14229385877,  43.5833476595992,
//            28.1792153343139,   -12.2003175839689, 8.03843204207197,
//            816.367835342705,   29.3090699107367,  64.9301513320287,
//            -16.9662478110515,  49.8604096110329,  1289.05587141977,
//            113.575172955276,   69.0804455262156,  -50.2871635866033,
//            21.9569319371031,   617.115603833222,  3.15227343078234,
//            17.458722809869,    -1.28601857752903, 0.536688135886396,
//            -992.124796005883,  5.25932352048495,  19.2182029962931,
//            0.654197031652291,  7.29287260005583,  -402.584001215848,
//            9.77802690862419,   53.3712994226198,  0.143815302490457,
//            -0.0968748878776697};
//     m_ekmean = {1.25000000229,        -4.20500056996787e-11,
//                 1.250000001142,       1.4210854715202e-16,
//                 3.90798504668055e-16, 3.5527136788005e-16};
//     m_ekstd = {se * 0.437364698489993, se * 0.408207051738512,
//                se * 0.437364698086024, sk * 29.0947832062987,
//                sk * 16.5344721292626,  sk * 29.0212420015475};
//     density = 1.1631613260e+01;
//   }
//   virtual double psi(const Vec6 &ek);
//   virtual std::pair<Mat6x6, Vec6> psi_drv(const Vec6 &ek);
//   virtual Vec6 psi_grad(const Vec6 &ek);
//
// private:
//   double s;
//   std::vector<double> m_C;
//   std::vector<double> m_ekmean;
//   std::vector<double> m_ekstd;
// };
//
// } // namespace hylc
// #endif /* end of include guard: _TESTMATERIAL_HPP_ */
