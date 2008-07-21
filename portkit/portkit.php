<?php
/*
    Copyright (c) 2008 flash.tato & theCor3

    Permission is hereby granted, free of charge, to any person
    obtaining a copy of this software and associated documentation
    files (the "Software"), to deal in the Software without
    restriction, including without limitation the rights to use,
    copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following
    conditions:

    The above copyright notice and this permission notice shall be
    included in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
    OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
    NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
    HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
    WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
    OTHER DEALINGS IN THE SOFTWARE.
*/

if( $argc <= 1 )
{
    echo "# ElfLoader port tool for V3x/E770/V1075/E1070\n";
    echo "# by flash.tato & theCor3\n";
    echo "Help:\n";
    echo "\t-sh: build library.def from .h files <-sh>\n";
    echo "\t-f:  build functions.pat <-f library.def functions.pat CG1.smg>\n";
    echo "\t-sf: build library.def from functions.pat <-sf functions.pat CG1.smg>\n";
}

$already_in = array( );

if( $argv[ 1 ] == '-sh' )
{
    $h = opendir( "./" );

    $output = "";

    $houtput = fopen( "./library.def", "w+" );

    while( $file = readdir( $h ) )
    {
        if( $file == '.' ||
            $file == '..' ||
            substr( $file, strlen( $file ) - 2, 2 ) != '.h' ||
            is_dir( $file ) ) continue;
            
        $file_content = file_get_contents( "./" . $file );

        preg_match_all("#typedef\s*([a-zA-Z0-9_* ]+)\s*\(\s*\*\s*([a-zA-Z0-9_]+)\s*\)\s*\((.*?)\);\r?\n?.*?0x([A-Fa-f0-9]{8});#s", $file_content, $retn, PREG_SET_ORDER );

        foreach( $retn as $c )
        {
            if( !in_array( str_replace( "f_", "", $c[ 2 ] ), $already_in ) )
            {
                $output .= str_replace( "f_", "", $c[ 2 ] ) . "=" . $c[ 4 ] . "\n";
                $already_in[ ] = str_replace( "f_", "", $c[ 2 ] );
            }
        }
    }

    fwrite( $houtput, $output );
    fclose( $houtput );
}
elseif( $argv[ 1 ] == '-f' )
{
    $houtput = fopen( $argv[ 3 ], "w+" );
    
    $lib = file_get_contents( "./" . $argv[ 2 ] );
    $input = file_get_contents( "./" . $argv[ 4 ] );

    $functions = explode( "\n", $lib );
    
    foreach( $functions as $function )
    {
        $data = explode( "=", $function );
        $address = hexdec( $data[ 1 ] ) - hexdec( "10040000" );

        $code = "";
        for( $i = 0; $i < 17; $i++ )
            $code .= $input[ $address + $i ];

        $hx_code = "";
        
        echo $data[ 0 ] . " at 0x" . dechex( $address ) + hexdec( "10040000" ) . "\n";
        $dt = unpack( "C*", $code );
        
        for( $i = 1; $i < count( $dt ); $i++ )
        {
            $hx_code .= sprintf( "%02X", $dt[ $i ] );
        }

        $towrite = $data[ 0 ] . "=" . $hx_code;
        fwrite( $houtput, $towrite . "\n" );
    }

    fclose( $houtput );
}
elseif( $argv[ 1 ] == '-sf' )
{
    $lib = file_get_contents( "./" . $argv[ 2 ] );
    $input = file_get_contents( "./" . $argv[ 3 ] );
    $newlib = fopen( "./newlib.sym", "w+" );

    $functions = explode( "\n", $lib );
    
    foreach( $functions as $function )
    {
        $binary = "";
        $data = explode( "=", $function );

        $binary = $data[ 1 ];

        $faddr = find_bytes( $input, $binary );
        
        if( $faddr > 1 )
        {
            printf( "%s at %X\n", $data[ 0 ], $faddr + hexdec( "10040000" ) );
            fwrite( $newlib, sprintf( "%s=%x\n", $data[ 0 ], $faddr + hexdec( "10040000" ) ) );
        }
        else
        {
            printf( "%s NOT Found!\n", $data[ 0 ] );
            fwrite( $newlib, sprintf( "%s=NOT FOUND SEARCH IT MANUALLY\n", $data[ 0 ] ) );
        }
    }
    
    fclose( $newlib );
}

function find_bytes( $content, $bytes, $offset = 0 )
{
	if(preg_match("#^[0-9A-Fa-f]*$#", $bytes))
	{
		$a = pack("H*", $bytes);
		return strpos($content, $a, $offset);
	}
	else
	{
		$to_find = "#" . preg_replace("#([0-9A-Fa-f]{2})#", "\\\\x$1", $bytes) . "#";
		$to_find = str_replace("??", ".", $to_find);
		preg_match($to_find, $content, $t, PREG_OFFSET_CAPTURE, $offset);
		return $t[ 0 ][ 1 ];
	}
}

?>
