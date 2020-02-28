var addon = require('bindings')('hello');

const result = addon.sayHello(); // world
console.log('result:', result);
