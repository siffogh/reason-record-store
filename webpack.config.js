const path = require('path');
const HtmlWebpackPlugin = require('html-webpack-plugin')
const CleanWebpackPlugin = require('clean-webpack-plugin');
const outputDir = path.resolve(__dirname, './build');

const isProd = process.env.NODE_ENV === 'production';

module.exports = {
  entry: {
    app: './src/Index.bs.js'
  },
  mode: isProd ? 'production' : 'development',
  output: {
    path: outputDir,
    filename: 'Index.js'
  },
  plugins: [
    new CleanWebpackPlugin(['build']),
    new HtmlWebpackPlugin({
      template: 'src/index.html'
    })
  ],
  devServer: {
    contentBase: './build',
    port: process.env.PORT || 8000
  }
};