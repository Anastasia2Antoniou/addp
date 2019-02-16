#ifndef _ETL_H_
#define _ETL_H_
#include <utility>
#include <map>
#include <vector>

namespace etl 
 {
  std::map<char, int> transform(const std::map<int, std::vector<char>>&);
};
#endif /* _ETL_H_ */