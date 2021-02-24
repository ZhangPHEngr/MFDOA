#pragma once
struct radar
{
    int m;
    int lda;
};
extern "C" __declspec(dllexport)  int evd(struct radar r, float *A, float*W);
