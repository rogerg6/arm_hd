

#ifndef _I2C_CONTROLLER_H
#define _I2C_CONTROLLER_H

typedef struct i2c_msg {
	unsigned int addr,	/* 7bit */
	int flags,			/* 0->write, 1->read */
	int len,
	int cnt_tranfer,
	unsigned int * buf
}i2c_msg, p_i2c_msg;

typedef struct i2c_controller {
	void (*init)(void);
	void (*master_tranfer)(p_i2c_msg p, int num);
	char * name;
}i2c_controller, p_i2c_controller;

#endif   /* _I2C_CONTROLLER_H */