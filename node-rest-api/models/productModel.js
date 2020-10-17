let products = require('../data/products.json');

const findAll = () => {
  return new Promise((resolve, reject) => {
    resolve(products);
  });
};

module.exports = {
  findAll,
};
