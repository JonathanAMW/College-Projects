# -*- mode: python ; coding: utf-8 -*-
block_cipher = None

def get_mediapipe_path():
    import mediapipe
    mediapipe_path = mediapipe.__path__[0]
    return mediapipe_path

a = Analysis(
    ['Handtracking.py'],
    pathex=[],
    binaries=[],
    datas=[],
    hiddenimports=[],
    hookspath=[],
    hooksconfig={},
    runtime_hooks=[],
    excludes=[],
    noarchive=False,
)
#pyz = PYZ(a.pure)
pyz = PYZ(a.pure, a.zipped_data, cipher=block_cipher)

mediapipe_tree = Tree(get_mediapipe_path(), prefix='mediapipe', excludes=["*.pyc"])
a.datas += mediapipe_tree
a.binaries = filter(lambda x: 'mediapipe' not in x[0], a.binaries)


exe = EXE(
    pyz,
    a.scripts,
    a.binaries,
    a.datas,
    [],
    name='Handtracking',
    debug=False,
    bootloader_ignore_signals=False,
    strip=False,
    upx=True,
    upx_exclude=[],
    runtime_tmpdir=None,
    console=True,
    disable_windowed_traceback=False,
    argv_emulation=False,
    target_arch=None,
    codesign_identity=None,
    entitlements_file=None,
)
