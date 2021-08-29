
float unk_gxm_text_draw(int param_1,int param_2,int param_3,uint param_4,ushort *param_5)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  undefined *puVar4;
  uint uVar5;
  int iVar6;
  void *uVar7;
  ushort *puVar7;
  ushort uVar8;
  int *piVar9;
  int *piVar10;
  char *pcVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  int local_1d8;
  int local_1d4;
  int local_1d0;
  int local_1cc;
  int auStack456;
  int *local_1c4;
  int *local_1c0;
  undefined4 uStack444;
  ushort local_1b8 [128];
  int local_b8;
  int local_b4;
  int local_b0;
  float local_ac;
  float local_a8;
  float local_a4;
  uint local_a0;
  int local_9c;
  uint local_98;
  uint local_94;
  float local_90;
  float local_8c;
  undefined *local_88;
  int local_84;
  int local_80;
  uint local_7c;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  short local_68;
  ushort *local_64;
  uint local_60;
  char local_5c;
  int local_58;
  uint local_54;
  
  piVar10 = &local_1d8;
  piVar9 = &local_1d8;
  local_88 = &DAT_8119cbec;
  local_8c = DAT_8119d434;
  local_b8 = 0;
  local_90 = DAT_8119d438;
  uVar5 = ((param_4 >> 0x18) * 0xa0) / 0xff;
  local_94 = DAT_8119d448 & 0x7f;
  local_6c = uVar5 << 0x18;
  local_b4 = param_3;
  local_b0 = param_1;
  local_98 = param_4;
  local_60 = param_4;
  local_58 = param_2;
  local_9c = FUN_8100b8ca(uVar5,local_94,(param_4 >> 0x18) * 0x505050a0);
  local_1c4 = (int *)0x0;
  iVar13 = 0;
  local_1c0 = (int *)0x0;
  uStack444 = 0;
  local_5c = '\0';
  local_78 = local_9c;
  local_54 = DAT_8119d46c;
  if ((DAT_8119d46c & 2) == 0) {
    local_74 = 0;
    iVar13 = 0;
    uVar8 = *param_5;
    iVar14 = local_74;
    while (uVar8 != 0) {
      param_5 = param_5 + 1;
      local_74 = iVar14;
      if (uVar8 == 0x2460) {
        *(undefined2 *)((int)piVar9 + 0x20) = 0x2665;
      }
      else {
        *(ushort *)((int)piVar9 + 0x20) = uVar8;
      }
      iVar13 = iVar13 + 1;
      piVar9 = (int *)((int)piVar9 + 2);
      iVar14 = local_74;
      uVar8 = *param_5;
    }
    local_1b8[iVar13] = (ushort)iVar14;
  }
  else {
    uVar8 = *param_5;
    iVar12 = 0;
    local_74 = 0;
    iVar6 = 0;
    puVar7 = param_5 + 1;
    iVar14 = local_74;
    while (uVar8 != 0) {
      local_74 = iVar14;
      if (uVar8 == 0x3010) {
        *(undefined2 *)((int)piVar10 + 0x20) = 0x3000;
        iVar6 = 1;
        iVar12 = iVar12 + 1;
        piVar10 = (int *)(undefined *)((int)piVar10 + 2);
      }
      else {
        if (uVar8 == 0x3011) {
          *(undefined2 *)((int)piVar10 + 0x20) = 0x3000;
          iVar6 = iVar14;
          iVar12 = iVar12 + 1;
          piVar10 = (int *)(undefined *)((int)piVar10 + 2);
        }
      }
      if (uVar8 == 0x2460) {
        if (iVar6 == 0) {
          *(undefined2 *)((int)piVar10 + 0x20) = 0x2665;
          piVar10 = (int *)((int)piVar10 + 2);
          iVar12 = iVar12 + 1;
        }
        else {
          if (DAT_811f6628 != 0) {
            *(char *)(DAT_811f6628 + iVar13 + 0x4be) = (char)local_74;
            iVar13 = (int)(short)((short)iVar13 + 1);
          }
        }
      }
      else {
        if ((uVar8 < 0x2461) || (0x2469 < uVar8)) {
          *(ushort *)((int)piVar10 + 0x20) = uVar8;
          piVar10 = (int *)((int)piVar10 + 2);
          iVar12 = iVar12 + 1;
        }
        else {
          if (DAT_811f6628 != 0) {
            *(char *)(DAT_811f6628 + iVar13 + 0x4be) = (char)uVar8 + -0x60;
            iVar13 = (int)(short)((short)iVar13 + 1);
          }
        }
      }
      uVar8 = *puVar7;
      puVar7 = puVar7 + 1;
      iVar14 = local_74;
    }
    local_1b8[iVar12] = (ushort)iVar14;
  }
  puVar4 = local_88;
  iVar13 = local_b8;
  local_68 = (short)iVar14;
  if ((local_54 & 9) != 0) {
    puVar7 = local_1b8;
    uVar5 = local_54;
    local_74 = iVar14;
    uVar8 = local_1b8[0];
    if (local_1b8[0] != 0) {
      do {
        puVar7 = puVar7 + 1;
        iVar12 = FUN_81008824(uVar8);
        iVar12 = (int)*(char *)(*(int *)(puVar4 + iVar12 * 8 + 0x48) + 6) + *(int *)(puVar4 + 0x850)
        ;
        if (uVar8 == 10) {
          iVar12 = iVar13;
          if ((*(uint *)(puVar4 + 0x880) & 1) == 0) {
            local_1d4 = -iVar14;
            FUN_81070b90(&auStack456,&local_1d4);
            iVar14 = iVar13;
          }
          else {
            local_1d8 = -(iVar14 / 2);
            FUN_81070b90(&auStack456,&local_1d8);
            iVar14 = iVar13;
          }
        }
        iVar14 = iVar14 + iVar12;
        uVar8 = *puVar7;
      } while (*puVar7 != 0);
      uVar5 = *(uint *)(puVar4 + 0x880);
      local_74 = iVar14;
    }
    if ((uVar5 & 1) == 0) {
      local_1cc = -local_74;
      FUN_81070b90(&auStack456,&local_1cc);
      iVar14 = *local_1c4;
    }
    else {
      local_1d0 = -(local_74 / 2);
      FUN_81070b90(&auStack456,&local_1d0);
      iVar14 = *local_1c4;
    }
  }
  local_74 = iVar14;
  local_64 = local_1b8 + 1;
  if (local_1b8[0] != 0) {
    local_ac = (float)(longlong)local_b0;
    lVar1 = (longlong)local_b4;
    do {
      iVar13 = FUN_81008824(local_1b8[0]);
      iVar14 = *(int *)(local_88 + iVar13 * 8 + 0x48);
      local_a0 = (uint)*(byte *)(iVar14 + 2);
      local_7c = (uint)*(byte *)(iVar14 + 3);
      local_a4 = (float)(longlong)(int)local_a0 * local_8c;
      local_a8 = (float)(longlong)(int)local_7c * local_90;
      local_80 = (iVar13 + ((int)(iVar13 + ((uint)(iVar13 >> 0x1f) >> 0x1c)) >> 4) * -0x10) * 0x20 +
                 2;
      local_84 = ((int)(iVar13 + ((uint)(iVar13 >> 4) >> 0x1c)) >> 4) * 0x20 + 1;
      fVar15 = local_ac + (float)(longlong)(*(char *)(iVar14 + 4) + local_74) * local_8c;
      local_70 = (int)*(char *)(iVar14 + 6) + *(int *)(local_88 + 0x850);
      fVar16 = (float)(longlong)local_58 + (float)(longlong)(int)*(char *)(iVar14 + 5) * local_90;
      if (local_1b8[0] == 10) {
        local_70 = local_b8;
        if ((*(uint *)(local_88 + 0x880) & 4) == 0) {
          local_74 = local_b8;
          local_58 = *(int *)(local_88 + 0x864) + local_58;
          if (((*(uint *)(local_88 + 0x880) & 1) != 0) &&
             ((uint)(int)local_5c < (uint)((int)local_1c0 - (int)local_1c4 >> 2))) {
            local_5c = local_5c + '\x01';
            local_74 = local_1c4[local_5c];
          }
        }
LAB_81008e2a:
        local_74 = local_74 + local_70;
      }
      else {
        if ((local_94 != 1) && (local_94 == 2)) {
          iVar13 = local_80 + local_a0;
          fVar17 = local_a4 + fVar15;
          fVar18 = local_a8 + fVar16;
          lVar2 = (longlong)local_80;
          pcVar11 = &DAT_8109afe8;
          lVar3 = (longlong)local_84;
          iVar14 = 8;
          do {
            local_78 = FUN_81008766((float)(longlong)(int)*pcVar11 + fVar15,
                                    (float)(longlong)(int)pcVar11[1] + fVar16,
                                    (float)(longlong)(int)*pcVar11 + fVar17,
                                    (float)(longlong)(int)pcVar11[1] + fVar18,(float)lVar1,
                                    (float)lVar2,(float)lVar3,(float)(longlong)iVar13,local_78,
                                    local_6c);
            iVar14 = iVar14 + -1;
            pcVar11 = pcVar11 + 2;
          } while (iVar14 != 0);
        }
        if ((*(uint *)(local_88 + 0x880) & 2) == 0) {
LAB_81008dd6:
          local_78 = FUN_81008766(fVar15,fVar16,local_a4 + fVar15,local_a8 + fVar16,(float)lVar1,
                                  (float)(longlong)local_80,(float)(longlong)local_84,
                                  (float)(longlong)(int)(local_80 + local_a0),local_78,local_60);
          goto LAB_81008e2a;
        }
        if (local_1b8[0] == 0x3010) {
          local_60 = 0xff0000ff;
          if ((DAT_811f6628 != 0) &&
             (*(int *)(DAT_811f6628 + local_68 * 4 + 0x4c8) = local_74 + local_b0,
             *(char *)(DAT_811f6628 + local_68 + 0x4c3) != '\0')) {
            local_60 = 0xff00ff00;
          }
        }
        else {
          if (local_1b8[0] != 0x3011) goto LAB_81008dd6;
          if (DAT_811f6628 != 0) {
            *(int *)(DAT_811f6628 + local_68 * 4 + 0x4dc) = local_74 + local_b0;
          }
          local_68 = local_68 + 1;
          local_60 = local_98;
        }
      }
      puVar7 = local_64 + 1;
      local_1b8[0] = *local_64;
      local_64 = puVar7;
    } while (local_1b8[0] != 0);
  }
  iVar12 = local_74;
  iVar14 = local_9c;
  iVar13 = local_b4;
  uVar5 = local_78 - local_9c;
  if (uVar5 / 0x18 != 0) {
    FUN_8100b8d6(local_78,local_78,uVar5,uVar5 * -0x55555555);
    FUN_8100cb52();
    FUN_8100b986(1);
    FUN_8100cd64(1);
    FUN_8100b952(2);
    FUN_8100c2de(0xffffffff);
    FUN_8100c588();
    puVar4 = local_88;
    FUN_8100b9a6(*(undefined4 *)(local_88 + 0x860),0);
    FUN_8100b9c4((float)(longlong)iVar13);
    if ((*(uint *)(puVar4 + 0x85c) & 0x80) == 0) {
      uVar7 = *(void **)(puVar4 + 0x874);
    }
    else {
      uVar7 = *(void **)(puVar4 + 0x878);
    }
    sceGxmTextureSetPalette(*(undefined4 *)(puVar4 + 0x870),uVar7);
    FUN_81013278(0,*(undefined4 *)(puVar4 + 0x870));
    FUN_8100c288(0x3b000000,0x3b000000);
    FUN_8100c17a(0,iVar14);
    FUN_8100c0fc(1,uVar5 / 0x18);
    FUN_8100cb66(0);
  }
  fVar15 = (float)(longlong)iVar12 * local_8c;
  if (local_1c4 != (int *)0x0) {
    local_1c0 = local_1c4;
    _ZdlPv();
  }
  return ROUND(fVar15 + 0.5);
}

