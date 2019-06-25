#ifndef _MRC_SOUND_H_
#define _MRC_SOUND_H_

/*
此文件为系统内部封装的函数实现了MRPAPI库<mrc_sound.h>的部分功能
本文件只相当于帮助文件，没有任何实际意义，也就是说在这里增加或修改定义不会有任何效果
如果你需要增加定义，请定义在其他文件中,要使用以下所有接口请在你的代码中增加“#include "base.h"”和“#include "sound.h"”
*/



//系统没有预先定义以下两个结构
enum{
_MIDI=1,
_WAVE,
_MP3,
_AMR,
_PCM,
_M4A,
_AMR_WB
};

typedef struct
{
    int32 pos;
}T_DSM_AUDIO_POS;




/*
	每次播放前需调用
	[in]:播放设备类型_MIDI－_AMR
	[return]:	0 初始化成功
			-1 初始化失败
			1 不支持该功能
*/
int32 soundinit(int32 type);

/*
	加载音频文件
	[in]
	type:设备类型
	filename:数据文件名称，相对路径，GB编码，这里注意的是从mrp外部读取文件
    [return]:	0 初始化成功
    -1 初始化失败
    1 不支持该功能
*/
int32 soundloadfile(int32 type, char* filename);
/*
	播放音频文件
	[in]
	type:设备类型
	block:1：阻塞式向底层发送播放请求；0：非阻塞凡是向底层发送播放请求
	loop:0：单次播放；1：循环播放；2：nes pcm 播放方式
    [return]:	0 初始化成功
    -1 初始化失败
    1 不支持该功能
*/
int32 soundplay(int32 type, int32 block, int32 loop);

/*
	暂停播放音频文件
	[in]
	type:设备类型
    [return]:	0 初始化成功
    -1 初始化失败
    1 不支持该功能
*/
int32 soundpause(int32 type);
/*
	继续播放音频文件
	[in]
	type:设备类型
    [return]:	0 初始化成功
    -1 初始化失败
    1 不支持该功能
*/
int32 soundresume(int32 type);
/*
	停止播放音频文件
	[in]
	type:设备类型
    [return]:	0 初始化成功
    -1 初始化失败
    1 不支持该功能
*/
int32 soundstop(int32 type);
/*
	关闭设备
	[in]
	type:设备类型
    [return]:	0 初始化成功
    -1 初始化失败
    1 不支持该功能
*/
int32 soundclose(int32 type);
/*
	音量调节
	[in]
	volume:音量大小0~5
    [return]:	0 初始化成功
    -1 初始化失败
    1 不支持该功能
*/
int32 setvolume(int32 volume);

/*
	获取音乐的总时间秒S
	[out]
	p:指向这个数据结构（T_DSM_AUDIO_POS）的指针的指针，
	这个数据结构的值就是总的时间
    [return]:	0 初始化成功
    -1 初始化失败
    1 不支持该功能

	注：mtk上此接口在以文件形式播放的时候有效。
*/
int32 getsoundtotaltime(int32 type, uint8** p);

/*
	获取当前已经播放的时间秒S
	[out]
	p:指向这个数据结构（T_DSM_AUDIO_POS）的指针的指针，
	这个数据结构的值就是已经播放的时间
    [return]:	0 初始化成功
    -1 初始化失败
    1 不支持该功能

	注：mtk上此接口在以文件形式播放的时候有效。
*/

int32 getsoundcurtime(int32 type, uint8** p);


/*
	获取当前已经播放的时间毫秒ms
	[out]
	p:指向这个数据结构（T_DSM_AUDIO_POS）的指针的指针，
	这个数据结构的值就是已经播放的时间
    [return]:	0 初始化成功
    -1 初始化失败
    1 不支持该功能

	注：mtk上此接口在以文件形式播放的时候有效。
*/

int32 getsoundcurtimems(int32 type, uint8** p);

/*
设置播放位置，相对文件或者缓冲的起始位置的偏移量
［IN］
	SOUND_POS pos：相对文件或者缓冲的起始位置的偏移量
    [return]:	0 初始化成功
    -1 初始化失败
    1 不支持该功能
*/
int32 setplaypos(int32 type,T_DSM_AUDIO_POS* pos);

/*
设置播放时间，相对文件或者缓冲的起始时间的偏移量
［IN］
	SOUND_POS pos：相对文件或者缓冲的起始时间的偏移量，单位：ms
    [return]:	0 初始化成功
    -1 初始化失败
    1 不支持该功能
*/
int32 setplaytime(int32 type,T_DSM_AUDIO_POS* pos);

/*
获取当前设备的状态
［IN］
	无
［return］
	设备状态值  成功
    -1 初始化失败
    1 不支持该功能

*/
int32 getdevicestate(int32 type);
#endif
 