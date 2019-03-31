#pragma once

#include "Store.h"

#include <string>

class Order
{
public:
  void add(const std::string& article, size_t quantity);
  void fill(Store&);

private:
  std::string _article;
  size_t _quantity;
};
