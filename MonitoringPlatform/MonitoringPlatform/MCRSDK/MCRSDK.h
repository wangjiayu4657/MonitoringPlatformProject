/*
 * MCRSDK.h
 *
 *  Created on: 2014-3-17
 *      Author: weilinfeng
 */

#ifndef MCRSDK_H_
#define MCRSDK_H_

#ifdef __cpluscplus
#define MCRSDK_API extern
#define MCRSDK_API extern
#else
#define  MCRSDKAPI
#define  MCRSDKAPI
#endif


/** @fn bool InitLib()
 *   @brief 初始化MCRSDK
 *   @param [in] 无
 *   @param [out] 无
 *   @return true - 初始化成功; false - 初始化库失败
 */
MCRSDKAPI bool InitLib();

/** @fn bool FiniLib()
 *   @brief 释放MCRSDK
 *   @param [in] 无
 *   @param [out] 无
 *   @return 无
 */
MCRSDKAPI bool FiniLib();

/** @fn bool SetPrint()
 *   @brief 设置日志 打印
 *   @param [in] iflag无 0-关闭日志，1-打印日志，2-将日志写到logPath的文件中
 *   @param [out] logPath- 日志文件路径
 *   @return 无
 */
MCRSDKAPI bool SetPrint(int iflag, const char* logPath);


#endif /* MCRSDK_H_ */
