## 2021-09-01
Me:

> I need to call a game function that takes arguments using the s0->31 float
> registers. Is there a way I can enforce that calling convention in C?  
> currently I'm not sure exactly what the code it generates does, but it defo
> appears to use higher registers  
> is this custom linker script territory?

CreepNT:

> it's the default calling convention iirc  
> passing `-mfloat-abi=<soft/hard> -mfpu=neon-fp16` may help too
>
> last time I checked default calling convention was using `s` registers but I
> may be wrong, try with those compiler flags to see if it helps  
> also be careful with varargs functions (like `int printf(char* fmt, ...)`)
> because the calling convention is different (no `s` registers)

Hmm!
