#ifndef _TESTMATERIAL_HPP_
#define _TESTMATERIAL_HPP_

#include "BaseMaterial.hpp"
#include <vector>

namespace hylc {
class TestMaterial : public BaseMaterial {
public:
  TestMaterial() {
    s = 1;         // 1e-2;
    double sk = 1; // 1e2; // debug, if bigger less curvy stuff
    // m_C = {24.880611357547,      30.9876859608939,   39.7198514665143,
    //        66.0881961218422,     -7.86982975935647,  0.0601702641758691,
    //        2.15049756442683,     -0.107739735775619, 2.18841192157357,
    //        0.789682883004569,    2.56995996381918,   0.311080303346407,
    //        38.7333643362365,     64.3308391120656,   -8.65483439454951,
    //        0.819894741423599,    24.8003831367493,   41.7141638558948,
    //        -15.0088957192384,    -41.2494582266692,  21.1812920608958,
    //        -19.9183334537448,    0.0216486869178135, -12.6495157375629,
    //        -0.00304599699300749, 3.57574897373618,   3.82153811589053,
    //        -7.95854800267124,    0.0444923410988428, 5.12138768953863,
    //        4.06996487713863};
    // m_ekmean = {1.305,
    //             -5.55111512312578e-18,
    //             1.305,
    //             2.8421709430404e-16,
    //             7.105427357601e-17,
    //             2.8421709430404e-16};
    // m_ekstd = {0.55107951910275, 0.412289121692097, 0.55107951910275,
    //            sk*69.9783516331833, sk*34.9891758155864,
    //            sk*69.9783516331833};

    // NOTE energy from this is off by factor of 0.85*0.85 ish
    // because i forgot to scale the ref area with proto
    m_C = {-5.75324018414577,     -14.3525546724176,     4.39464866667865,
           2.418709667566,        -0.400795586174937,    0.338904481037995,
           -1.54496000881669,     0.0254971010251254,    0.0823113198960042,
           0.000831535383413999,  0.13863292353844,      12.282010743722,
           2.83279522827334,      2.20461361849148,      -0.407136255055274,
           0.399627714661661,     -3.20146116174713,     0.0117925950573016,
           0.177756195525871,     -0.000898503840220473, -0.000988954104673727,
           6.91432184903441,      0.00903835359295149,   0.131614776522008,
           -0.000770327820603794, 0.0582341691936409,    -2.05478368243092,
           0.0150558679037681,    0.245898807828304,     0.00117763953016899,
           -0.0429379838072606};
    m_ekmean = {1.305,
                -5.55111512312578e-18,
                1.305,
                2.8421709430404e-16,
                7.105427357601e-17,
                2.8421709430404e-16};
    m_ekstd = {0.43736469869565,      0.408207051975081,
               0.437364698392629,     sk * 291.111346991829,
               sk * 162.453284671786, sk * 290.987334018003};
  }
  virtual double psi(const Vec6 &ek);
  virtual std::pair<Mat6x6, Vec6> psi_drv(const Vec6 &ek);

private:
  double s;
  std::vector<double> m_C;
  std::vector<double> m_ekmean;
  std::vector<double> m_ekstd;
};

} // namespace hylc
#endif /* end of include guard: _TESTMATERIAL_HPP_ */
