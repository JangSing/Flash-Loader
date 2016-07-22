# Load cbuild script to help build C program
load File.join(File.dirname(__FILE__), 'cbuild.rb')

config_dll = {
  :verbose      => :yes,
  :compiler     => 'gcc',
  :linker       => 'gcc',
# :include_path => [''],
  :user_define  => ['ADD_EXPORT'],
# :library_path => 'lib',
# :library => [''],
# :linker_script => 'MyLinkerScript.ld',
# :compiler_options => ['-DOK'],                      # Other compiler options
  :linker_options => ['-s',
                      '-shared',
                      '-Wl,--subsystem,windows'],     # Other linker options
  :option_keys  => {:library => '-l',
                    :library_path => '-L',
                    :include_path => '-I',
                    :output_file => '-o',
                    :compile => '-c',
                    :linker_script => '-T',
                    :define => '-D'}
}

config_main = {
  :verbose      => :yes,
  :compiler     => 'gcc',
  :linker       => 'gcc',
  :include_path => ['src'],
# :user_define  => [''],
  :library_path => 'build/release/dll',
  :library => ['TestDll'],
# :linker_script => 'MyLinkerScript.ld',
# :compiler_options => ['-DOK'],          # Other compiler options
  :linker_options => ['-s'],              # Other linker options
  :option_keys  => {:library => '-l',
                    :library_path => '-L',
                    :include_path => '-I',
                    :output_file => '-o',
                    :compile => '-c',
                    :linker_script => '-T',
                    :define => '-D'}
}


namespace :build do
  dll_library = "build/release/dll/TestDll.dll"
  main_exe = "build/release/dll/main.exe"
  desc 'Build DLL'
  task :dll do
    dep_list = compile_all('src', 'build/release/dll', config_dll)
    link_all(getDependers(dep_list), dll_library, config_dll)
    Rake::Task[dll_library].invoke
  end
  
  desc 'Build main'
  task :main => :dll do
    dep_list = compile_all('src/main', 'build/release/dll', config_main)
    link_all(getDependers(dep_list), main_exe, config_main)
    Rake::Task[main_exe].invoke
  end 
end
