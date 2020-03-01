var addon = require('bindings')('hello');

const result = addon.sayHello(); // world
console.log('typeof result:', typeof result, ',result:', result);
