.data 
var1 dd 3
bool DWORD  10

.code

myProc proc
	mov eax,var1
	shl eax,1
	mov var1,eax
	;mov eax,var1
	shl eax,1
	ret
myProc endp

makeitDouble proc
	mov eax,ecx
	shl eax,1
	ret
makeitDouble endp

makeMul proc
	mov eax,ecx
	imul eax,edx
	ret
makeMul endp

doString proc
	;mov rax,0		; init rax
	inc rcx			; pour avoir la 2eme lettre de la chaine
	mov al,[rcx]	; il faut faire référence à rcx (et non pas à eax) pour avoir l'adresse complète (sinon exception)
	ret				; renvoie le premier char de la chaine (dans AL)
doString endp

doCharLen proc
	mov rbx,0		; init rbx
	mov rax,0		; init rax
read:
	mov al,[rcx]	; lit un caractere
	cmp al,0		; fin de chaine  ?
	je fin			; oui => fin
	inc ebx			; inc. compteur
	inc rcx			; ajuste pointeur 
	jmp read
fin:
	mov eax,ebx
	ret				; renvoie la longueur de la chaine (dans eax)
doCharLen endp

doStrLen proc
	mov rbx,0		; init rbx
	mov rax,0		; init rax
	add rcx,8		; ajustement pour la structure en mémoire des string en C++
read:
	mov al,[rcx]	; lit un caractere
	cmp al,0		; fin de chaine  ?
	je fin			; oui => fin
	inc ebx			; inc. compteur
	inc rcx			; ajuste pointeur 
	jmp read
fin:
	mov eax,ebx
	ret				; renvoie la longueur de la chaine (dans eax)
doStrLen endp

doTab proc
	shl rdx,2 ; indice du tableau mul by 4 (4 octets par élément du tableau)
	mov eax, dword ptr [rcx+rdx] ; élément du tableau ==> rax
	add bool,eax ; pour vérifier que la variable est commune à toutes les proc  (cf. proc doReadLocal) 
	ret
doTab endp

doReadLocal proc
	mov eax, bool ; = eax,dword ptr [bool]
	; equivant à :
	; 	lea rbx,bool
	;	mov eax,dword ptr [rbx]
	ret
doReadLocal endp

BubbleSort proc
; rcx : array ptr
; rdx tab length
; rbx : booean = changed
init: 
	mov r8,rcx		; save array ptr
	mov r9,rdx		; save length				
	cmp rdx,1		; 1 element only ?
	ja suite1		; yes, exit
	ret

suite1:
	mov rcx,r8					; init array ptr
	mov rdx,r9					; init length 
	mov rbx, 0					; changed = false
suite2:
	mov eax, dword ptr [rcx]	; ptr to first element 
	cmp eax, dword ptr [rcx+4]	; cmp to next element 
	ja permut
	jmp s2
permut:
	push rax					; save element tab[i] : dword ptr [rcx]
	mov eax,dword ptr [rcx+4]	; eax = next element : dword ptr [rcx+4]
	mov dword ptr [rcx], eax	; tab[i] = tab[i+1]
	pop rax						; get element tab[i]
	mov dword ptr [rcx+4],eax	; tab[i+1]= i
	mov ebx,1					; changed = true

s2:
	add rcx,4					; adjust ptr to next element 
	dec rdx						; dec length count 
	cmp rdx,1					; end of array ?
	jne suite2					; no ==> next element 

	cmp rbx,1					; changed ?
	je suite1					; yes : restart
fin:
	ret
BubbleSort endp


end