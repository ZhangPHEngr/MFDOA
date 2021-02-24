#pragma once
extern "C" __declspec(dllexport)  int MFDOA(float* Tracks_out, int* cnt_tracks_out, float* Data_music_batch, float* Data_RD_batch, float* Data_mea_batch, float*Data_mer_batch, float* Data_in, struct Radar_para radar, struct TBD_para TBD, struct ProcSetting ps);
