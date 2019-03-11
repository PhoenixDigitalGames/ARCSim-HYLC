#include "strain.hpp"

using namespace hylc;
using namespace hylc::mathematica;

Vec6 hylc::mathematica::ek(const Vec18 &xloc, const Mat2x2 &invDm,
                           const Real &A, const Real &thetarest0,
                           const Real &thetarest1, const Real &thetarest2,
                           const Real &l0, const Real &l1, const Real &l2,
                           const Vec2 &t0, const Vec2 &t1, const Vec2 &t2) {
  // define output
  Vec6 out;

  Real c2 = xloc(0);
  Real c3 = -c2;
  Real c1 = invDm(0, 0);
  Real c7 = invDm(1, 0);
  Real c14 = xloc(1);
  Real c15 = -c14;
  Real c25 = xloc(2);
  Real c26 = -c25;
  Real c4 = xloc(3);
  Real c5 = c3 + c4;
  Real c6 = c1 * c5;
  Real c8 = xloc(6);
  Real c9 = c3 + c8;
  Real c10 = c7 * c9;
  Real c11 = c10 + c6;
  Real c16 = xloc(4);
  Real c17 = c15 + c16;
  Real c18 = c1 * c17;
  Real c19 = xloc(7);
  Real c21 = c15 + c19;
  Real c22 = c21 * c7;
  Real c23 = c18 + c22;
  Real c36 = invDm(0, 1);
  Real c38 = invDm(1, 1);
  Real c27 = xloc(5);
  Real c28 = c26 + c27;
  Real c29 = c1 * c28;
  Real c30 = xloc(8);
  Real c31 = c26 + c30;
  Real c32 = c31 * c7;
  Real c33 = c29 + c32;
  Real c37 = c36 * c5;
  Real c39 = c38 * c9;
  Real c40 = c37 + c39;
  Real c43 = c17 * c36;
  Real c44 = c21 * c38;
  Real c45 = c43 + c44;
  Real c47 = c28 * c36;
  Real c48 = c31 * c38;
  Real c49 = c47 + c48;
  Real c60 = t0(0);
  Real c61 = Power(c60, 2);
  Real c75 = Power(c2, 2);
  Real c76 = Power(c16, 2);
  Real c78 = Power(c27, 2);
  Real c86 = xloc(9);
  Real c95 = xloc(10);
  Real c102 = Power(c4, 2);
  Real c115 = xloc(11);
  Real c107 = c8 * c86;
  Real c108 = c8 + c86;
  Real c109 = -(c108 * c4);
  Real c127 = c115 + c30;
  Real c140 = c30 * c86;
  Real c142 = c115 * c8;
  Real c111 = c19 + c95;
  Real c146 = 2 * c27;
  Real c147 = -c30;
  Real c148 = -c115;
  Real c149 = c146 + c147 + c148;
  Real c125 = Power(c14, 2);
  Real c106 = Power(c25, 2);
  Real c170 = -c95;
  Real c173 = c8 * c95;
  Real c65 = t1(0);
  Real c66 = Power(c65, 2);
  Real c227 = Power(c8, 2);
  Real c233 = Power(c19, 2);
  Real c243 = Power(c30, 2);
  Real c246 = xloc(12);
  Real c259 = xloc(13);
  Real c272 = xloc(14);
  Real c157 = c19 * c78;
  Real c289 = -c246;
  Real c290 = c289 + c8;
  Real c298 = -c259;
  Real c299 = c19 + c298;
  Real c307 = -c272;
  Real c308 = c30 + c307;
  Real c192 = -(c19 * c2 * c27);
  Real c193 = c16 * c2 * c30;
  Real c201 = -c8;
  Real c325 = c299 * c4;
  Real c70 = t2(0);
  Real c71 = Power(c70, 2);
  Real c82 = c16 * c19 * c75;
  Real c84 = c27 * c30 * c75;
  Real c380 = xloc(15);
  Real c169 = -c19;
  Real c395 = xloc(16);
  Real c389 = -c227;
  Real c390 = -c380;
  Real c391 = c390 + c8;
  Real c392 = c391 * c4;
  Real c393 = c380 * c8;
  Real c306 = c147 + c27;
  Real c410 = xloc(17);
  Real c396 = -c395;
  Real c397 = c19 + c396;
  Real c411 = -c410;
  Real c412 = c30 + c411;
  Real c442 = c397 * c4;
  Real c443 = c395 * c8;
  Real c468 = c27 * c391;
  Real c469 = c30 * c380;
  Real c56 = 1 / A;
  Real c57 = 1 / l0;
  Real c58 = 1 / l1;
  Real c59 = 1 / l2;
  Real c62 = thetarest0 / 2.;
  Real c63 = Tan(c62);
  Real c67 = thetarest1 / 2.;
  Real c68 = Tan(c67);
  Real c72 = thetarest2 / 2.;
  Real c73 = Tan(c72);
  Real c509 = t0(1);
  Real c77 = -(c75 * c76);
  Real c79 = -(c75 * c78);
  Real c80 = c2 * c76 * c8;
  Real c81 = c2 * c78 * c8;
  Real c83 = -(c16 * c19 * c2 * c4);
  Real c85 = -(c2 * c27 * c30 * c4);
  Real c87 = c2 * c76 * c86;
  Real c88 = c2 * c78 * c86;
  Real c89 = -(c76 * c8 * c86);
  Real c90 = -(c78 * c8 * c86);
  Real c91 = -(c16 * c19 * c2 * c86);
  Real c92 = c16 * c19 * c4 * c86;
  Real c93 = -(c2 * c27 * c30 * c86);
  Real c94 = c27 * c30 * c4 * c86;
  Real c96 = c16 * c75 * c95;
  Real c97 = -(c16 * c2 * c4 * c95);
  Real c98 = -(c16 * c2 * c8 * c95);
  Real c99 = c16 * c4 * c8 * c95;
  Real c100 = -(c19 * c75 * c95);
  Real c101 = 2 * c19 * c2 * c4 * c95;
  Real c103 = -(c102 * c19 * c95);
  Real c104 = -(c19 * c78 * c95);
  Real c105 = c16 * c27 * c30 * c95;
  Real c110 = c19 * c95;
  Real c112 = -(c111 * c16);
  Real c113 = c102 + c107 + c109 + c110 + c112 + c76;
  Real c114 = -(c106 * c113);
  Real c116 = c115 * c27 * c75;
  Real c117 = -(c115 * c2 * c27 * c4);
  Real c118 = -(c115 * c2 * c27 * c8);
  Real c119 = c115 * c27 * c4 * c8;
  Real c120 = c115 * c16 * c19 * c27;
  Real c121 = -(c115 * c30 * c75);
  Real c122 = 2 * c115 * c2 * c30 * c4;
  Real c123 = -(c102 * c115 * c30);
  Real c124 = -(c115 * c30 * c76);
  Real c126 = c115 * c30;
  Real c128 = -(c127 * c27);
  Real c129 = c102 + c107 + c109 + c126 + c128 + c78;
  Real c130 = -(c125 * c129);
  Real c131 = -(c16 * c19 * c27);
  Real c132 = c30 * c76;
  Real c133 = 2 * c27 * c8 * c86;
  Real c134 = -(c16 * c27 * c95);
  Real c135 = 2 * c19 * c27 * c95;
  Real c136 = -(c16 * c30 * c95);
  Real c137 = c115 * c76;
  Real c138 = -(c115 * c16 * c19);
  Real c139 = c102 * c127;
  Real c141 = c108 * c27;
  Real c143 = c140 + c141 + c142;
  Real c144 = -(c143 * c4);
  Real c145 = -(c108 * c27);
  Real c150 = c149 * c4;
  Real c151 = c140 + c142 + c145 + c150;
  Real c152 = c151 * c2;
  Real c153 = c131 + c132 + c133 + c134 + c135 + c136 + c137 + c138 + c139 +
              c144 + c152;
  Real c154 = c153 * c25;
  Real c155 = -(c16 * c4 * c8);
  Real c156 = c102 * c19;
  Real c158 = -(c16 * c27 * c30);
  Real c159 = -(c16 * c4 * c86);
  Real c160 = 2 * c16 * c8 * c86;
  Real c161 = -(c19 * c4 * c86);
  Real c162 = c102 * c95;
  Real c163 = c78 * c95;
  Real c164 = -(c4 * c8 * c95);
  Real c165 = -(c27 * c30 * c95);
  Real c166 = c19 * c86;
  Real c167 = -(c108 * c16);
  Real c168 = 2 * c16;
  Real c171 = c168 + c169 + c170;
  Real c172 = c171 * c4;
  Real c174 = c166 + c167 + c172 + c173;
  Real c175 = c174 * c2;
  Real c176 = -(c115 * c16 * c27);
  Real c177 = -(c115 * c19 * c27);
  Real c178 = 2 * c115 * c16 * c30;
  Real c179 = c30 * c95;
  Real c180 = -(c111 * c27);
  Real c181 = c149 * c16;
  Real c182 = c115 * c19;
  Real c183 = c179 + c180 + c181 + c182;
  Real c184 = c183 * c25;
  Real c185 = c155 + c156 + c157 + c158 + c159 + c160 + c161 + c162 + c163 +
              c164 + c165 + c175 + c176 + c177 + c178 + c184;
  Real c186 = c14 * c185;
  Real c187 = c100 + c101 + c103 + c104 + c105 + c114 + c116 + c117 + c118 +
              c119 + c120 + c121 + c122 + c123 + c124 + c130 + c154 + c186 +
              c77 + c79 + c80 + c81 + c82 + c83 + c84 + c85 + c87 + c88 + c89 +
              c90 + c91 + c92 + c93 + c94 + c96 + c97 + c98 + c99;
  Real c188 = -2 * c2 * c4;
  Real c189 = -2 * c14 * c16;
  Real c190 = -2 * c25 * c27;
  Real c191 = c102 + c106 + c125 + c188 + c189 + c190 + c75 + c76 + c78;
  Real c194 = c19 * c27 * c86;
  Real c195 = -(c16 * c30 * c86);
  Real c196 = c2 * c27 * c95;
  Real c197 = -(c27 * c8 * c95);
  Real c198 = -(c2 * c30 * c95);
  Real c199 = c30 * c4 * c95;
  Real c200 = -(c19 * c86);
  Real c202 = c201 + c86;
  Real c203 = c16 * c202;
  Real c204 = c170 + c19;
  Real c205 = c204 * c4;
  Real c206 = c173 + c200 + c203 + c205;
  Real c207 = c206 * c25;
  Real c208 = -(c115 * c16 * c2);
  Real c209 = c115 * c16 * c8;
  Real c210 = c115 * c19 * c2;
  Real c211 = -(c115 * c19 * c4);
  Real c212 = -c86;
  Real c213 = c212 + c8;
  Real c214 = c213 * c27;
  Real c215 = -(c115 * c8);
  Real c216 = c115 + c147;
  Real c217 = c216 * c4;
  Real c218 = c140 + c214 + c215 + c217;
  Real c219 = c14 * c218;
  Real c220 = c192 + c193 + c194 + c195 + c196 + c197 + c198 + c199 + c207 +
              c208 + c209 + c210 + c211 + c219;
  Real c221 = c191 * c220;
  Real c222 = ArcTan(c187, c221);
  Real c223 = c222 / 2.;
  Real c224 = Tan(c223);
  Real c511 = t1(1);
  Real c226 = -(c25 * c27 * c4 * c8);
  Real c228 = -(c227 * c76);
  Real c229 = c227 * c25 * c27;
  Real c230 = -(c227 * c78);
  Real c231 = -(c16 * c19 * c25 * c27);
  Real c232 = 2 * c16 * c19 * c4 * c8;
  Real c234 = -(c102 * c233);
  Real c235 = c233 * c25 * c27;
  Real c236 = -(c233 * c78);
  Real c237 = c102 * c25 * c30;
  Real c238 = c25 * c30 * c76;
  Real c239 = -(c25 * c30 * c4 * c8);
  Real c240 = 2 * c27 * c30 * c4 * c8;
  Real c241 = -(c16 * c19 * c25 * c30);
  Real c242 = 2 * c16 * c19 * c27 * c30;
  Real c244 = -(c102 * c243);
  Real c245 = -(c243 * c76);
  Real c247 = c246 * c25 * c27 * c4;
  Real c248 = c246 * c76 * c8;
  Real c249 = -(c246 * c25 * c27 * c8);
  Real c250 = c246 * c78 * c8;
  Real c251 = -(c16 * c19 * c246 * c4);
  Real c252 = -(c16 * c19 * c246 * c8);
  Real c253 = c233 * c246 * c4;
  Real c254 = -(c246 * c25 * c30 * c4);
  Real c255 = -(c246 * c27 * c30 * c4);
  Real c256 = c246 * c25 * c30 * c8;
  Real c257 = -(c246 * c27 * c30 * c8);
  Real c258 = c243 * c246 * c4;
  Real c260 = c16 * c25 * c259 * c27;
  Real c261 = -(c16 * c259 * c4 * c8);
  Real c262 = c16 * c227 * c259;
  Real c263 = c102 * c19 * c259;
  Real c264 = -(c19 * c25 * c259 * c27);
  Real c265 = c19 * c259 * c78;
  Real c266 = -(c19 * c259 * c4 * c8);
  Real c267 = -(c16 * c25 * c259 * c30);
  Real c268 = -(c16 * c259 * c27 * c30);
  Real c269 = c19 * c25 * c259 * c30;
  Real c270 = -(c19 * c259 * c27 * c30);
  Real c271 = c16 * c243 * c259;
  Real c273 = -(c102 * c25 * c272);
  Real c274 = -(c25 * c272 * c76);
  Real c275 = 2 * c25 * c272 * c4 * c8;
  Real c276 = -(c27 * c272 * c4 * c8);
  Real c277 = -(c227 * c25 * c272);
  Real c278 = c227 * c27 * c272;
  Real c279 = 2 * c16 * c19 * c25 * c272;
  Real c280 = -(c16 * c19 * c27 * c272);
  Real c281 = -(c233 * c25 * c272);
  Real c282 = c233 * c27 * c272;
  Real c283 = c102 * c272 * c30;
  Real c284 = c272 * c30 * c76;
  Real c285 = -(c272 * c30 * c4 * c8);
  Real c286 = -(c16 * c19 * c272 * c30);
  Real c287 = -(c19 * c27 * c30);
  Real c288 = c19 * c246 * c8;
  Real c291 = c16 * c290;
  Real c292 = c19 * c246;
  Real c293 = -2 * c259;
  Real c294 = c19 + c293;
  Real c295 = c294 * c8;
  Real c296 = c291 + c292 + c295;
  Real c297 = -(c296 * c4);
  Real c300 = c102 * c299;
  Real c301 = -(c259 * c78);
  Real c302 = -(c227 * c259);
  Real c303 = 2 * c259 * c27 * c30;
  Real c304 = -(c243 * c259);
  Real c305 = -(c246 * c8);
  Real c309 = -(c306 * c308);
  Real c310 = c227 + c305 + c309;
  Real c311 = c16 * c310;
  Real c312 = -(c19 * c27 * c272);
  Real c313 = c19 * c272 * c30;
  Real c314 = c157 + c287 + c288 + c297 + c300 + c301 + c302 + c303 + c304 +
              c311 + c312 + c313;
  Real c315 = c14 * c314;
  Real c316 = c233 * c4;
  Real c317 = c243 * c4;
  Real c318 = c290 * c76;
  Real c319 = c290 * c78;
  Real c320 = -(c233 * c246);
  Real c321 = -(c243 * c246);
  Real c322 = -(c19 * c259 * c4);
  Real c323 = c19 * c259 * c8;
  Real c324 = -2 * c19 * c246;
  Real c326 = c19 + c259;
  Real c327 = c326 * c8;
  Real c328 = c324 + c325 + c327;
  Real c329 = -(c16 * c328);
  Real c330 = -(c272 * c30 * c4);
  Real c331 = c272 * c30 * c8;
  Real c332 = -2 * c246 * c30;
  Real c333 = c308 * c4;
  Real c334 = c272 + c30;
  Real c335 = c334 * c8;
  Real c336 = c332 + c333 + c335;
  Real c337 = -(c27 * c336);
  Real c338 = c316 + c317 + c318 + c319 + c320 + c321 + c322 + c323 + c329 +
              c330 + c331 + c337;
  Real c339 = c2 * c338;
  Real c340 = c226 + c228 + c229 + c230 + c231 + c232 + c234 + c235 + c236 +
              c237 + c238 + c239 + c240 + c241 + c242 + c244 + c245 + c247 +
              c248 + c249 + c250 + c251 + c252 + c253 + c254 + c255 + c256 +
              c257 + c258 + c260 + c261 + c262 + c263 + c264 + c265 + c266 +
              c267 + c268 + c269 + c270 + c271 + c273 + c274 + c275 + c276 +
              c277 + c278 + c279 + c280 + c281 + c282 + c283 + c284 + c285 +
              c286 + c315 + c339;
  Real c341 = -2 * c4 * c8;
  Real c342 = -2 * c16 * c19;
  Real c343 = -2 * c27 * c30;
  Real c344 = c102 + c227 + c233 + c243 + c341 + c342 + c343 + c76 + c78;
  Real c345 = c19 * c246 * c27;
  Real c346 = -(c16 * c246 * c30);
  Real c347 = c2 * c259 * c27;
  Real c348 = -(c259 * c27 * c8);
  Real c349 = -(c2 * c259 * c30);
  Real c350 = c259 * c30 * c4;
  Real c351 = -(c19 * c246);
  Real c352 = c201 + c246;
  Real c353 = c16 * c352;
  Real c354 = c259 * c8;
  Real c355 = c325 + c351 + c353 + c354;
  Real c356 = c25 * c355;
  Real c357 = -(c16 * c2 * c272);
  Real c358 = c16 * c272 * c8;
  Real c359 = c19 * c2 * c272;
  Real c360 = -(c19 * c272 * c4);
  Real c361 = c27 * c290;
  Real c362 = c246 * c30;
  Real c363 = -(c272 * c8);
  Real c364 = c147 + c272;
  Real c365 = c364 * c4;
  Real c366 = c361 + c362 + c363 + c365;
  Real c367 = c14 * c366;
  Real c368 = c192 + c193 + c345 + c346 + c347 + c348 + c349 + c350 + c356 +
              c357 + c358 + c359 + c360 + c367;
  Real c369 = c344 * c368;
  Real c370 = ArcTan(c340, c369);
  Real c371 = c370 / 2.;
  Real c372 = Tan(c371);
  Real c513 = t2(1);
  Real c374 = -(c16 * c19 * c2 * c8);
  Real c375 = -(c233 * c75);
  Real c376 = c2 * c233 * c4;
  Real c377 = -(c2 * c27 * c30 * c8);
  Real c378 = -(c243 * c75);
  Real c379 = c2 * c243 * c4;
  Real c381 = -(c16 * c19 * c2 * c380);
  Real c382 = c16 * c19 * c380 * c8;
  Real c383 = c2 * c233 * c380;
  Real c384 = -(c233 * c380 * c4);
  Real c385 = -(c2 * c27 * c30 * c380);
  Real c386 = c27 * c30 * c380 * c8;
  Real c387 = c2 * c243 * c380;
  Real c388 = -(c243 * c380 * c4);
  Real c394 = c16 + c169;
  Real c398 = c394 * c397;
  Real c399 = c389 + c392 + c393 + c398;
  Real c400 = c106 * c399;
  Real c401 = -(c16 * c395 * c75);
  Real c402 = 2 * c16 * c2 * c395 * c8;
  Real c403 = -(c16 * c227 * c395);
  Real c404 = c19 * c395 * c75;
  Real c405 = -(c19 * c2 * c395 * c4);
  Real c406 = -(c19 * c2 * c395 * c8);
  Real c407 = c19 * c395 * c4 * c8;
  Real c408 = c19 * c27 * c30 * c395;
  Real c409 = -(c16 * c243 * c395);
  Real c413 = c306 * c412;
  Real c414 = c389 + c392 + c393 + c413;
  Real c415 = c125 * c414;
  Real c416 = -(c27 * c410 * c75);
  Real c417 = 2 * c2 * c27 * c410 * c8;
  Real c418 = -(c227 * c27 * c410);
  Real c419 = -(c233 * c27 * c410);
  Real c420 = c30 * c410 * c75;
  Real c421 = -(c2 * c30 * c4 * c410);
  Real c422 = -(c2 * c30 * c410 * c8);
  Real c423 = c30 * c4 * c410 * c8;
  Real c424 = c16 * c19 * c30 * c410;
  Real c425 = -(c16 * c227);
  Real c426 = c19 * c25 * c27;
  Real c427 = c19 * c4 * c8;
  Real c428 = -2 * c19 * c25 * c30;
  Real c429 = c19 * c27 * c30;
  Real c430 = c16 * c380 * c8;
  Real c431 = -2 * c19 * c380 * c4;
  Real c432 = c19 * c380 * c8;
  Real c433 = -(c25 * c27 * c395);
  Real c434 = c395 * c4 * c8;
  Real c435 = -(c227 * c395);
  Real c436 = c25 * c30 * c395;
  Real c437 = c27 * c30 * c395;
  Real c438 = -(c243 * c395);
  Real c439 = -2 * c19 * c8;
  Real c440 = c16 * c391;
  Real c441 = c19 * c380;
  Real c444 = c439 + c440 + c441 + c442 + c443;
  Real c445 = c2 * c444;
  Real c446 = c147 + c25;
  Real c447 = c16 * c412 * c446;
  Real c448 = c19 * c25 * c410;
  Real c449 = -2 * c19 * c27 * c410;
  Real c450 = c19 * c30 * c410;
  Real c451 = c425 + c426 + c427 + c428 + c429 + c430 + c431 + c432 + c433 +
              c434 + c435 + c436 + c437 + c438 + c445 + c447 + c448 + c449 +
              c450;
  Real c452 = -(c14 * c451);
  Real c453 = c30 * c4 * c8;
  Real c454 = c16 * c19 * c30;
  Real c455 = -2 * c30 * c380 * c4;
  Real c456 = c30 * c380 * c8;
  Real c457 = -2 * c16 * c30 * c395;
  Real c458 = c19 * c30 * c395;
  Real c459 = -(c380 * c8);
  Real c460 = -(c19 * c395);
  Real c461 = c227 + c233 + c459 + c460;
  Real c462 = -(c27 * c461);
  Real c463 = c4 * c410 * c8;
  Real c464 = -(c227 * c410);
  Real c465 = c16 * c19 * c410;
  Real c466 = -(c233 * c410);
  Real c467 = -2 * c30 * c8;
  Real c470 = c4 * c412;
  Real c471 = c410 * c8;
  Real c472 = c467 + c468 + c469 + c470 + c471;
  Real c473 = c2 * c472;
  Real c474 = c453 + c454 + c455 + c456 + c457 + c458 + c462 + c463 + c464 +
              c465 + c466 + c473;
  Real c475 = -(c25 * c474);
  Real c476 = c374 + c375 + c376 + c377 + c378 + c379 + c381 + c382 + c383 +
              c384 + c385 + c386 + c387 + c388 + c400 + c401 + c402 + c403 +
              c404 + c405 + c406 + c407 + c408 + c409 + c415 + c416 + c417 +
              c418 + c419 + c420 + c421 + c422 + c423 + c424 + c452 + c475 +
              c82 + c84;
  Real c477 = -2 * c2 * c8;
  Real c478 = -2 * c14 * c19;
  Real c479 = -2 * c25 * c30;
  Real c480 = c106 + c125 + c227 + c233 + c243 + c477 + c478 + c479 + c75;
  Real c481 = c19 * c27 * c380;
  Real c482 = -(c16 * c30 * c380);
  Real c483 = c2 * c27 * c395;
  Real c484 = -(c27 * c395 * c8);
  Real c485 = -(c2 * c30 * c395);
  Real c486 = c30 * c395 * c4;
  Real c487 = -(c19 * c380);
  Real c488 = c201 + c380;
  Real c489 = c16 * c488;
  Real c490 = c442 + c443 + c487 + c489;
  Real c491 = c25 * c490;
  Real c492 = -(c16 * c2 * c410);
  Real c493 = c16 * c410 * c8;
  Real c494 = c19 * c2 * c410;
  Real c495 = -(c19 * c4 * c410);
  Real c496 = -(c410 * c8);
  Real c497 = c147 + c410;
  Real c498 = c4 * c497;
  Real c499 = c468 + c469 + c496 + c498;
  Real c500 = c14 * c499;
  Real c501 = c192 + c193 + c481 + c482 + c483 + c484 + c485 + c486 + c491 +
              c492 + c493 + c494 + c495 + c500;
  Real c502 = c480 * c501;
  Real c503 = ArcTan(c476, c502);
  Real c504 = c503 / 2.;
  Real c505 = Tan(c504);
  Real c520 = Power(c509, 2);
  Real c522 = Power(c511, 2);
  Real c524 = Power(c513, 2);
  out(0) = Power(c11, 2) + Power(c23, 2) + Power(c33, 2);
  out(1) = c11 * c40 + c23 * c45 + c33 * c49;
  out(2) = Power(c40, 2) + Power(c45, 2) + Power(c49, 2);
  out(3) = c56 * c57 * c58 * c59 *
           (l1 * l2 * c224 * c61 - l1 * l2 * c61 * c63 + l0 * l2 * c372 * c66 -
            l0 * l2 * c66 * c68 + l0 * l1 * c505 * c71 - l0 * l1 * c71 * c73);
  out(4) = c56 * c57 * c58 * c59 *
           (l1 * l2 * c224 * c509 * c60 - l1 * l2 * c509 * c60 * c63 +
            l0 * l2 * c372 * c511 * c65 - l0 * l2 * c511 * c65 * c68 +
            l0 * l1 * c505 * c513 * c70 - l0 * l1 * c513 * c70 * c73);
  out(5) =
      c56 * c57 * c58 * c59 *
      (l1 * l2 * c224 * c520 + l0 * l2 * c372 * c522 + l0 * l1 * c505 * c524 -
       l1 * l2 * c520 * c63 - l0 * l2 * c522 * c68 - l0 * l1 * c524 * c73);

  return out;
}
