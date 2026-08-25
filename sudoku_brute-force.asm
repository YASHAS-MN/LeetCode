section .data           ; idh array na store maadoke ondh section

board:
    db 5,3,0,0,7,0,0,0,0
    db 6,0,0,1,9,5,0,0,0
    db 0,9,8,0,0,0,0,6,0

    db 8,0,0,0,6,0,0,0,3
    db 4,0,0,8,0,3,0,0,1
    db 7,0,0,0,2,0,0,0,6

    db 0,6,0,0,0,0,2,8,0
    db 0,0,0,4,1,9,0,0,5
    db 0,0,0,0,8,0,0,7,9
    
newline:

db 10  ; idhu new line print maadoke, just like '\n'

;--------------------------------------------------------------------------------------------
section .bss   ; ee sec alli temp values store maadodh, like for loop alli 'i' iddhange

output: ; green al enen idiyo avella user defined names just as same as variables
    resb 1

;--------------------------------------------------------------------------------------------
section .text   ; illi we'll actually define the fn sol(pos)

global _start ;idhu global func and var na declare maadakke startig point
    
sol:    ;idh same sol(pos) funtion, illi pos na RDI reg al store madtivi, return value as 1/0 na RAX al store madtivi
    cmp rdi, 81 ;if(pos == 81) tara ne rdi -> pos, if ->cmp
    je solve_success ;je andre jump equal, andre if rdi=81 return 1 anta
    
    mov al, [board + rdi]
    
    cmp al, 0 
    jne solve_filled
    
    mov rsi, 1 ; idh num, 1-9 numbers a store madutthe to try
    
try_num:    ; for(int num=1; num<10; num++)
        call valid ; int valid(pos, num)
        
        cmp rax, 1 
        jne try_next ; idh en andre, valid function na karyutthe via call valid, then valid cuntion exe agutthe, adh rax alli value return madutthe, adhunna 1 g compare madtivi illi, if equal bandre valid illa, next number g jump aagu anta
        
        mov [board + rdi], sil ; board[pos] = num
        
        push rdi ; iv ered en andre stack tara for loop indh ele na store madoke
        push rsi
        
        inc rdi  ; idh next pos g hogutthe and the sol(pos) na karyutthe
        call sol ; sol(pos+1)
        
        pop rsi
        pop rdi
        
        cmp rax, 1
        je solve_success
        
        mov byte [board + rdi], 0 ; idh board[pos] = 0;
        
try_next:
        inc rsi
        
        cmp rsi, 10
        jne try_num
        
        mov rax, 0 
        ret 
        
solve_filled:
        inc rdi
        call sol 
        ret
    
solve_success:
        mov rax, 1
        ret 

valid:
        mov rax, rdi ;temp =pos
        
        xor rdx, rdx ; pos%9 and pos/9
        
        mov rcx, 9 ; divisor = 9 
        
        div rcx
        
        mov r8, rax ;row
        mov r9, rdx ;col 
        
        xor rcx, rcx ; row check, illi rcx, rcx, andre loop na initalize maadodh 0 g
        
check_row:
        mov rax, r8
        imul rax, 9 
        add rax, rcx ; totally row*9+i 
        
        mov dl, [board + rax]
        
        cmp dl, sil
        je invalid
        
        inc rcx
        cmp rcx, 9 
        jne check_row ; illige row check aith
        
        xor rcx, rcx ; idh col ge loop init madutthe

check_col:
        mov rax, rcx
        imul rax, 9 
        add rax, r9
        mov dl, [board + rax]
        
        cmp dl, sil
        je invalid
        
        inc rcx
        cmp rcx, 9 
        jne check_col ; illige row check mugith
        
        mov rax, r8 ; illinda 3*3 start aguth, idh boxRow varibale idh
        xor rdx, rdx
        mov rcx, 3
        div rcx
        imul rax, 3
        mov r10, rax
        
        mov rax, r9 ; idh 3*3 col ge
        xor rdx, rdx
        mov rcx, 3
        div rcx
        imul rax, 3
        mov r11, rax
        
        xor rcx, rcx
box_row:
        xor rdx, rdx
        
box_col:
        mov rax, r10            ;for(i=0;i<9;i++)
        add rax, rcx            ; for(j=0;i<9;j++)
        imul rax, 9             ;  if(board[(row+i)*9 + (col+j)] == num)
        add rax, r11            ; return 0
        add rax, rdx            
        mov al, [board+rax]
        
        cmp al, sil
        je invalid
        
        inc rdx
        cmp rdx, 3
        jne box_col
        
        inc rcx
        cmp rcx, 3
        jne box_row
        
        mov rax, 1 
        ret
        
invalid:
        mov rax, 0 
        ret
        
_start: ; this is the eqvi of int main()

    
        mov rdi, 0 
        call sol ; sol(0)
        
        xor r12, r12
        
print_loop:
        mov al, [board+r12]
        
        add al, '0'
        mov [output], al
        
        mov rax, 1 
        mov rdi, 1
        mov rsi, output
        mov rdx, 1 
        syscall
        
        inc r12
        mov rax, r12
        xor rdx, rdx
        mov rcx, 9 
        div rcx
        
        cmp rdx, 0 
        jne continue_print
        
        mov rax, 1 
        mov rdi, 1 
        mov rsi, newline
        mov rdx, 1 
        syscall
        
continue_print
        
        cmp r12, 81
        jne print_loop
        
        mov rax, 60 ; linux alli 60 -> exit()
        mov rdi, 0 ; return 0 tara idh
        syscall
