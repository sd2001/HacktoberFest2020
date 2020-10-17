const Product = require('../models/productModel');
const { getPostData } = require('../utils');

const getProducts = async (req, res) => {
  try {
    const products = await Product.findAll();
    res.writeHead(200, { 'Content-Type': 'application/json' }); // res.statusCode() + res.setHeader()
    res.end(JSON.stringify(products)); // res.write() + res.end()
  } catch (err) {
    console.log(err);
  }
};

const getProduct = async (req, res, id) => {
  try {
    const product = await Product.findById(id);
    if (!product) {
      res.writeHead(404, { 'Content-Type': 'application/json' });
      res.end(JSON.stringify({ message: 'Product Not Found' }));
    } else {
      res.writeHead(200, { 'Content-Type': 'application/json' });
      res.end(JSON.stringify(product));
    }
  } catch (err) {
    console.log(err);
  }
};

const createProduct = async (req, res) => {
  try {
    const body = await getPostData(req);

    const { title, description, price } = JSON.parse(body);

    const product = {
      title,
      description,
      price,
    };
    const newProduct = await Product.create(product);
    res.writeHead(201, { 'Content-Type': 'application/json' });
    return res.end(JSON.stringify(newProduct));
  } catch (err) {
    console.log(err);
  }
};

module.exports = {
  getProducts,
  getProduct,
  createProduct,
};
