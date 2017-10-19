#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>

#define ScreenWidth 800
#define ScreenHeight 600

int main()
{
	ALLEGRO_DISPLAY *display;
	ALLEGRO_PATH *path;

	if ( !al_init() ) {
		al_show_native_message_box( NULL, NULL, NULL, "Could not initialize Allegro 5", NULL, NULL );
		return -1;
	}

	al_set_new_display_flags( ALLEGRO_WINDOWED );
	display = al_create_display( ScreenWidth, ScreenHeight );
	path = al_get_standard_path( ALLEGRO_RESOURCES_PATH );
	al_set_path_filename(path, "times.ttf" );
	al_set_window_position( display, 200, 100 );
	al_set_window_title( display, "Fonts" );

	if ( !display ) {
		al_show_native_message_box( display, "Sample Title", "Display Settings", "Display Window was not created successfully", NULL,
			ALLEGRO_MESSAGEBOX_QUESTION );
		return -1;
	}

	al_init_font_addon();
	al_init_ttf_addon();

	ALLEGRO_FONT *font = al_load_ttf_font( al_path_cstr( path, '/' ), 36, NULL );
	al_draw_text( font, al_map_rgb( 44, 117, 255 ), ScreenWidth / 2, ScreenHeight / 2, ALLEGRO_ALIGN_CENTRE, "www.qualitycyberservices.com" );

	al_flip_display();
	al_rest( 10.0 );
	al_destroy_font( font );
	al_destroy_display( display );

	return 0;
}
