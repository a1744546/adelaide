// test header so that variables named in workshop
// questions will have known addresses we can test
	@x
	@y
	@sum
	@ptr
	@numbers
	@arr
// add your instructions after this line
@x
M=0
@sum
M=0
(loop)
    @10
    D=A
    @x
    D=M-D
    @END
    D;JGE
    
    @x
    D=M
    @sum
    M=M+D
    @x
    M=M+1
    @LOOP
    0;JMP
(END)
    @END
    0;JMP
