#ifndef SCROLL_H
#define SCROLL_H

#include <gb/gb.h>
#include "TilesInfo.h"
#include "MapInfo.h"

#define SPRITE_UNIQUE_ID(TILE_X, TILE_Y) ((0x00FF & TILE_X) | ((0xFF00 & (TILE_Y << 8))))

extern unsigned char* scroll_map;
extern INT16 scroll_x;
extern INT16 scroll_y;
extern UINT16 scroll_w;
extern UINT16 scroll_h;
extern UINT16 scroll_tiles_w;
extern UINT16 scroll_tiles_h;
extern UINT8  scroll_collisions[256];
extern UINT8  scroll_collisions_down[256];
extern UINT8 scroll_tile_info[256];
extern UINT8  scroll_bank;
extern UINT8 scroll_offset_x;
extern UINT8 scroll_offset_y;

extern struct Sprite* scroll_target;
extern UINT8 clamp_enabled;

extern UINT8 scroll_top_movement_limit;
extern UINT8 scroll_bottom_movement_limit;

void InitScrollTiles(UINT8 first_tile, struct TilesInfo* tile_data);
void InitScroll(struct MapInfo* map_data, const UINT8* coll_list, const UINT8* coll_list_down);
void ScrollSetMap(struct MapInfo* map_data);

void InitWindow(UINT8 x, UINT8 y, struct MapInfo* map);
void ScrollUpdateRow(INT16 x, INT16 y);
void ScrollUpdateColumn(INT16 x, INT16 y);
void MoveScroll(INT16 x, INT16 y);
void RefreshScroll();
void FinishPendingScrollUpdates();

UINT8* GetScrollTilePtr(UINT16 x, UINT16 y);
UINT8 GetScrollTile(UINT16 x, UINT16 y);
UINT8 ScrollFindTile(struct MapInfo* map, UINT8 tile,
	UINT8 start_x, UINT8 start_y, UINT8 w, UINT8 h,
	UINT16* x, UINT16* y);

#endif