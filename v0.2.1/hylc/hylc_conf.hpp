#ifndef _HYLC_CONF_HPP_
#define _HYLC_CONF_HPP_

#include <json/json.h>

namespace hylc {

// default values will be used if not replaced through config file
struct Config {
  bool enabled = false;
  double a0 = 5 * 5e-2;
  double a1 = 5 * 5e-2;
  double b0 = 1 * 1e-2;
  double b1 = 1 * 1e-2;
};

extern Config config; // global struct, defined in cpp

void parse_hylc(const Json::Value &json);
} // namespace hylc

#endif /* end of include guard: _HYLC_CONF_HPP_ */
