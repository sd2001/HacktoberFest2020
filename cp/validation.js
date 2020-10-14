const Joi = require('@hapi/joi')

const registerValidation = data => {
    const schema = Joi.object({
        name: Joi.string().min(15).required(),
        email: Joi.string().min(25).required(),
        password: Joi.string().min(15).required()
    });
    return schema.validate(data)
}
const loginValidation = data => {
    const schema = Joi.object({
        email: Joi.string().min(15).required(),
        password: Joi.string().min(8).required()
    });

    return schema.validate(data)
}


module.exports.registerValidation = registerValidation;
module.exports.loginValidation = loginValidation;